#include <iostream>
#include <cmath>

#include <raylib.h>

#include <invertedpendulum.h>
#include <unicycle.h>
#include <pid_controller.h>

// MMGS, millimeters, grams, seconds
const double GRAVITY = 9.81;
const double FRICTION_CONST = 0.4;

void printMousePos();

int main() 
{
    // MMGS, millimeters, grams, seconds
    // ----- Inverted Pendulum Variables -----
    double timeInterval = 0.01666;
    double massBase = 1;
    double massPendulum = 1;
    double lengthPendulum = 3;
    double xPos = 0; 
    double angle = 0;
    double xVel = 0;
    double angleVel = 0;
    double xAccel = 0;
    double angleAccel = 0;
    double appliedForce = 0;
    double timeElapsed = 0;

    // ----- PID Controller Variables -----
    double angleKp = 100;
    double angleKi = 0.1;
    double angleKd = 80;

    double xPosKp = 0.012;
    double xPosKi = 0;
    double xPosKd = 0.15;

    bool isControl = true; // is the controller on? is the control loop enabled?

    // ----- Visual Representation Variables -----
    int screenWidthPx = 800;
    int screenHeightPx = 450;
    int cartWidth = 50;
    int cartHeight = 30;
    int radius = 30;
    int pendulumLength = 100;
    double scaleFactor = 10.0;
    int newMouseX = 0;
    int oldMouseX = 0;
    int colorValue = 0;
    int firstParam = 0;
    int secondParam = 0;
    Color pendulumColor = SKYBLUE;
    Color baseColor = BEIGE;

    Unicycle pendulum(timeInterval, massBase, massPendulum, lengthPendulum, xPos, angle, xVel, angleVel, xAccel, angleAccel, appliedForce, FRICTION_CONST, GRAVITY, timeElapsed);

    PID_Controller xPosPID(xPosKp, xPosKi, xPosKd, 0, 0, 0, PI/6, -PI/6);
    double outerOutput;
    PID_Controller anglePID(angleKp, angleKi, angleKd, 0, 0, 0, 80, -80);
    double innerOutput;

    // ----- Raylib Setup -----
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidthPx, screenHeightPx, "Self-Balancing Unicycle");
    SetTargetFPS(120);

    // ----- Main game loop -----
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        screenWidthPx = GetScreenWidth();        
        screenHeightPx = GetScreenHeight();
        
        // TODO: controls for PID constants?
        //  ----- User Input ----- 
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            (timeInterval != 0) ? pendulum.setAppliedForce((newMouseX - oldMouseX) / (timeInterval * 10)) : pendulum.setAppliedForce(0);
        if (IsKeyDown(KEY_UP))
            timeInterval += 0.001;
        if (IsKeyDown(KEY_DOWN))
            timeInterval -= 0.001;
        if (IsKeyDown(KEY_SPACE))
            isControl = !isControl;
        if (IsKeyDown(KEY_R))
            pendulum.reset();

        oldMouseX = newMouseX;
        newMouseX = GetMouseX();

        // ----- PID Controller -----
        if (isControl) 
        {
            outerOutput = xPosPID.compute(pendulum.getXPosError());

            anglePID.setSetpoint(outerOutput); // output of xPos controller is input of angle controller (the more important controller) 

            innerOutput = anglePID.compute(pendulum.getAngleError());
            pendulum.setAppliedForce(-1 * innerOutput);
        }
       
        // ----- Display -----        
        // dynamic cart size based on window
        cartWidth = screenWidthPx / 10;
        cartHeight = cartWidth / 2;
        radius = cartHeight; 
        pendulumLength = cartWidth + cartHeight;

        DrawRectangle(0, (screenHeightPx / 2) + radius, screenWidthPx, screenHeightPx, BLACK); // the "ground"

        colorValue = static_cast<int>(abs(pendulum.getAngleError() * 255 * 10)); // Scale up the error and convert to int
        firstParam = (colorValue > 255) ? 255 : colorValue; // Cap the value at 255 if it exceeds
        secondParam = (colorValue > 255) ? 0 : 255 - firstParam; // Calculate the second parameter based on the first parameter
        pendulumColor = Color{ firstParam, secondParam, 0, 255 }; // Assign the color

        colorValue = static_cast<int>(abs(pendulum.getXPosError() * 255));
        firstParam = (colorValue > 255) ? 255 : colorValue;
        secondParam = (colorValue > 255) ? 0 : 255 - firstParam;
        baseColor = Color{ firstParam, secondParam, 0, 255 };

        pendulum.drawWheel(screenWidthPx, screenHeightPx, radius, scaleFactor, baseColor); // BEIGE = CLITERAL(Color){ 211, 176, 131, 255 }
        pendulum.drawPendulum(screenWidthPx, screenHeightPx, pendulumLength, scaleFactor, pendulumColor);

        // Display pendulum values
        DrawText(("xPos: " + std::to_string(pendulum.getXPos())).c_str(), 10, 10, 10, BLACK);
        DrawText(("angle: " + std::to_string(pendulum.getAngle())).c_str(), 10, 20, 10, BLACK);
        DrawText(("xVel: " + std::to_string(pendulum.getXVel())).c_str(), 10, 30, 10, BLACK);
        DrawText(("angleVel: " + std::to_string(pendulum.getAngleVel())).c_str(), 10, 40, 10, BLACK);
        DrawText(("xAccel: " + std::to_string(pendulum.getXAccel())).c_str(), 10, 50, 10, BLACK);
        DrawText(("angleAccel: " + std::to_string(pendulum.getAngleAccel())).c_str(), 10, 60, 10, BLACK);
        DrawText(("timeElapsed: " + std::to_string(pendulum.getTimeElapsed())).c_str(), 10, 70, 10, BLACK);
        DrawText(("appliedForce: " + std::to_string(pendulum.getAppliedForce())).c_str(), 10, 80, 10, BLACK);
        DrawText(("angleError: " + std::to_string(pendulum.getAngleError())).c_str(), 10, 90, 10, BLACK);
        DrawText(("xPosError: " + std::to_string(pendulum.getXPosError())).c_str(), 10, 100, 10, BLACK);
        DrawText(("xPosSetpoint: " + std::to_string(xPosPID.getSetpoint())).c_str(), 10, 110, 10, BLACK);
        DrawText(("mouseX: " + std::to_string(GetMouseX())).c_str(), 10, 120, 10, BLACK);

        // PID Control On/Off Display
        if (isControl)
        {
            DrawCircle(10, 150, 5, GREEN);
            DrawText("Control is ON", 20, 150, 10, BLACK);
        }
        else
        {
            DrawCircle(10, 150, 5, RED);
            DrawText("Control is OFF", 20, 150, 10, BLACK);
        }

        EndDrawing();

        // TODO: This invalidates the up and down arrows for speed control. Figure out how to fix that 
        timeInterval = GetFrameTime(); // should be deltaTime     
        pendulum.update(timeInterval); 
        xPosPID.setSetpoint(((GetMouseX()) - (screenWidthPx / 2)) / scaleFactor); // translate mouse x position to pendulum x
        pendulum.calculateErrors(anglePID.getSetpoint(), xPosPID.getSetpoint());
        pendulum.setAppliedForce(0); 

        // printMousePos();
    }
    CloseWindow();
    return 0;
}

void printMousePos()
{
    std::cout << GetMouseX() << ' ' << GetMouseY() << '\n';
    DrawCircle(GetMouseX(), GetMouseY(), 2, RED);
}