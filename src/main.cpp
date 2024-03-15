#include <iostream>
#include <cmath>

#include <raylib.h>

#include <invertedpendulum.h>
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
    double massBase = 5;
    double massPendulum = 5;
    double lengthPendulum = 3;
    double xPos = 0; 
    double angle = PI / 4;
    double xVel = 0;
    double angleVel = 0;
    double xAccel = 0;
    double angleAccel = 0;
    double appliedForce = 0;
    double timeElapsed = 0;

    // ----- Visual Representation Variables -----
    int screenWidthPx = 800;
    int screenHeightPx = 450;
    int yPos;
    int cartWidth = 50;
    int cartHeight = 30;
    int pendulumLength = 100;
    double scaleFactor = 10.0;
    double screenXPos;
    int newMouseX = 0;
    int oldMouseX = 0;

    InvertedPendulum pendulum(timeInterval, massBase, massPendulum, lengthPendulum, xPos, angle, xVel, angleVel, xAccel, angleAccel, appliedForce, FRICTION_CONST, GRAVITY, timeElapsed);
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(screenWidthPx, screenHeightPx, "ML Unicycle");

    SetTargetFPS(60);

    // ----- Main game loop -----
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        screenWidthPx = GetScreenWidth();        
        screenHeightPx = GetScreenHeight();
        
        // dynamic cart size based on window
        cartWidth = screenWidthPx / 10;
        cartHeight = cartWidth / 2;
        pendulumLength = cartWidth + cartHeight;
        
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
            (timeInterval != 0) ? pendulum.setAppliedForce((newMouseX - oldMouseX) / (timeInterval * 10)) : pendulum.setAppliedForce(0);
        if (IsKeyDown(KEY_UP))
            timeInterval += 0.001;
        if (IsKeyDown(KEY_DOWN))
            timeInterval -= 0.001;
        if (IsKeyDown(KEY_SPACE))
        {
            double oldTimeInterval;
            if (timeInterval != 0)
            {
                oldTimeInterval = timeInterval;
                timeInterval = 0;
            }
            else
            {
                timeInterval = oldTimeInterval;
            }
        }
        oldMouseX = newMouseX;
        newMouseX = GetMouseX();
       
        // TODO: create draw functions for the object, inside its class
        screenXPos = (screenWidthPx / 2) + (scaleFactor * pendulum.getXPos()); // use 0 for initial x, and scale up movement

        // Draw the cart
        yPos = screenHeightPx / 2;
        DrawRectangle((screenXPos - (cartWidth / 2)), yPos, cartWidth, cartHeight, BLACK);

        // Draw the pendulum
        DrawLine(
                screenXPos, yPos, // start line at base of cart

                // Get the end of the pendulum (updated)
                screenXPos + ((pendulumLength) * sin(pendulum.getAngle())),
                yPos - (pendulumLength) * cos(pendulum.getAngle()), 

                RED
                );
      
        pendulum.update(timeInterval);
        pendulum.calculateError();

        // Display pendulum values
        DrawText(("xPos: " + std::to_string(pendulum.getXPos())).c_str(), 10, 10, 10, BLACK);
        DrawText(("angle: " + std::to_string(pendulum.getAngle())).c_str(), 10, 20, 10, BLACK);
        DrawText(("xVel: " + std::to_string(pendulum.getXVel())).c_str(), 10, 30, 10, BLACK);
        DrawText(("angleVel: " + std::to_string(pendulum.getAngleVel())).c_str(), 10, 40, 10, BLACK);
        DrawText(("xAccel: " + std::to_string(pendulum.getXAccel())).c_str(), 10, 50, 10, BLACK);
        DrawText(("angleAccel: " + std::to_string(pendulum.getAngleAccel())).c_str(), 10, 60, 10, BLACK);
        DrawText(("timeElapsed: " + std::to_string(pendulum.getTimeElapsed())).c_str(), 10, 70, 10, BLACK);
        DrawText(("appliedForce: " + std::to_string(pendulum.getAppliedForce())).c_str(), 10, 80, 10, BLACK);
        DrawText(("screenXPos: " + std::to_string(screenXPos)).c_str(), 10, 90, 10, BLACK);
        DrawText(("error: " + std::to_string(pendulum.getError())).c_str(), 10, 100, 10, BLACK);
        
        pendulum.setAppliedForce(0); 

        EndDrawing();

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