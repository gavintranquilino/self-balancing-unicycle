#include <iostream>
#include <cmath>

#include <raylib.h>

#include <invertedpendulum.h>

int main() 
{
    const int SCREEN_WIDTH = 800;
    const int SCREEN_HEIGHT = 400;

    // MMGS, millimeters, grams, seconds

    // ----- Inverted Pendulum Variables -----

    // TODO: initialize gravity and friction as variables in this scope instead of manipulating in the header. I want to manipulate all aspects of the pendulum
    double timeInterval = 0.1;
    double massBase = 10;
    double massPendulum = 10;
    double lengthPendulum = 1;
    double xPos = 0; 
    double angle = PI / 4;
    double xVel = 0;
    double angleVel = 0;
    double xAccel = 0;
    double angleAccel = 0;
    double appliedForce = 0;
    double timeElapsed = 0;

    InvertedPendulum pendulum(timeInterval, massBase, massPendulum, lengthPendulum, xPos, angle, xVel, angleVel, xAccel, angleAccel, appliedForce, FRICTION_CONST, timeElapsed);
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cartpole simulation");

    SetTargetFPS(60);

    // ----- Visual Representation Variables -----
    int yPos = 200;
    int cartWidth = 50;
    int cartHeight = 30;
    int pendulumLength = 100;
    double scaleFactor = 10.0;
    double screenXPos;

    // ----- Main game loop -----
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(WHITE);
       
        // TODO: create draw functions for the object, inside its class
        screenXPos = (SCREEN_WIDTH / 2) + (scaleFactor * pendulum.getXPos()); // use 0 for initial x, and scale up movement

        // Draw the cart
        DrawRectangle((screenXPos - (cartWidth / 2)), yPos, cartWidth, cartHeight, BLACK);

        // Draw the pendulum
        DrawLine(
                screenXPos, yPos, // start line at base of cart

                // Get the end of the pendulum (updated)
                screenXPos + ((100) * sin(pendulum.getAngle())),
                yPos - (100) * cos(pendulum.getAngle()), 

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
        DrawText(("appliedForce: " + std::to_string(pendulum.getAppliedForce())).c_str(), 10, 80, 10, BLACK);
        DrawText(("screenXPos: " + std::to_string(screenXPos)).c_str(), 10, 90, 10, BLACK);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}