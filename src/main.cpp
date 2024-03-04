#include <iostream>
#include <cmath>

#include <raylib.h>

#include <bruh.h>
#include <invertedpendulum.h>

int main() 
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 450;

    // MMGS, millimeters, grams, seconds
    double timeInterval = 0.02;
    double massBase = 5;
    double massPendulum = 3;
    double lengthPendulum = 1;
    double xPos = SCREEN_WIDTH/ 2;
    double angle = PI/4; // Radians
    double xVel = 0;
    double angleVel = 0;
    double xAccel = 0;
    double angleAccel = 0;
    double appliedForce = 0;
    double timeElapsed = 0;

    InvertedPendulum pendulum(timeInterval, massBase, massPendulum, lengthPendulum, xPos, angle, xVel, angleVel, xAccel, angleAccel, appliedForce, FRICTION_CONST, timeElapsed);
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cartpole simulation");

    SetTargetFPS(30);

    // ----- Visual Representation Variables -----
    int yPos = 200;
    int cartWidth = 50;
    int cartHeight = 30;

    // ----- Main game loop -----
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(WHITE);
    
        // change inverted pendulum x position with arrow keys
        if (IsKeyDown(KEY_RIGHT)) 
            pendulum.setXPos(pendulum.getXPos() + 10);
        if (IsKeyDown(KEY_LEFT)) 
            pendulum.setXPos(pendulum.getXPos() - 10);
        if (IsKeyDown(KEY_UP)) 
            pendulum.setAngle(pendulum.getAngle() + (PI/12));
        if (IsKeyDown(KEY_DOWN)) 
            pendulum.setAngle(pendulum.getAngle() - (PI/12));

        // Draw the cart
        DrawRectangle(pendulum.getXPos() - cartWidth / 2, yPos, cartWidth, cartHeight, BLACK);

        // Draw the pendulum
        DrawLine(
                pendulum.getXPos(), yPos, // start line at base of cart

                // Get the end of the pendulum (updated)
                pendulum.getXPos() + ((pendulum.getLengthPendulum() + 50) * sin(pendulum.getAngle())),
                yPos - (pendulum.getLengthPendulum() + 50) * cos(pendulum.getAngle()), 

                RED
                );
      
        pendulum.update(timeInterval);

        // ----- Print Mouse Position -----
        std::cout << GetMouseX() << ' ' << GetMouseY() << '\n';
        DrawCircle(GetMouseX(), GetMouseY(), 2, RED);

        // print all the pendulum member variables to the window with a label on what the value is
        DrawText(("xPos: " + std::to_string(pendulum.getXPos())).c_str(), 10, 10, 10, BLACK);
        DrawText(("angle: " + std::to_string(pendulum.getAngle())).c_str(), 10, 20, 10, BLACK);
        DrawText(("xVel: " + std::to_string(pendulum.getXVel())).c_str(), 10, 30, 10, BLACK);
        DrawText(("angleVel: " + std::to_string(pendulum.getAngleVel())).c_str(), 10, 40, 10, BLACK);
        DrawText(("xAccel: " + std::to_string(pendulum.getXAccel())).c_str(), 10, 50, 10, BLACK);
        DrawText(("angleAccel: " + std::to_string(pendulum.getAngleAccel())).c_str(), 10, 60, 10, BLACK);
        DrawText(("timeElapsed: " + std::to_string(pendulum.getTimeElapsed())).c_str(), 10, 70, 10, BLACK);
        DrawText(("appliedForce: " + std::to_string(appliedForce)).c_str(), 10, 80, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}