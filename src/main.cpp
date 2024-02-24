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
    double timeInterval = 0.01;
    double massBase = 50;
    double massPendulum = 50;
    double lengthPendulum = 50;
    double xPos = SCREEN_WIDTH/ 2;
    double angle = PI / 4; // Radians
    double xVel = 0;
    double angleVel = 0;
    double xAccel = 0;
    double angleAccel = 0;
    double appliedForce = 0;
    double timeElapsed = 0;

    InvertedPendulum pendulum(timeInterval, massBase, massPendulum, lengthPendulum, xPos, angle, xVel, angleVel, xAccel, angleAccel, appliedForce, timeElapsed);
    
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "cartpole simulation");

    SetTargetFPS(60);

    std::cout << MASS_BASE << ' ' << MASS_PENDULUM << ' ' << LENGTH_PENDULUM << '\n';

    // ----- Visual Representation Variables -----
    int yPos = 200;
    int cartWidth = 50;
    int cartHeight = 20;

    // ----- Main game loop -----
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(WHITE);
    
        // change inverted pendulum x position with arrow keys
        if (IsKeyDown(KEY_RIGHT)) 
        {
            pendulum.setXPos(pendulum.getXPos() + 10);
        }
        if (IsKeyDown(KEY_LEFT)) 
        {
            pendulum.setXPos(pendulum.getXPos() - 10);
        }
        if (IsKeyDown(KEY_UP)) 
        {
            pendulum.setAngle(pendulum.getAngle() + (PI/6));
        }
        if (IsKeyDown(KEY_DOWN)) 
        {
            pendulum.setAngle(pendulum.getAngle() - (PI/6));
        }

        // ----- Draw cart at base x position -----
        DrawRectangle(pendulum.getXPos() - cartWidth / 2, yPos, cartWidth, cartHeight, BLACK);

        // ----- Draw pendulum as a line in the angle where angle at 0 is up -----
        double pendulumX = pendulum.getXPos();
        double pendulumY = yPos;

        // Draw a line starting form pendulumX and Y and ending at pendulumX + length * sin(angle) and pendulumY + length * cos(angle)
        DrawLine(
                pendulumX, pendulumY, // start line at base of cart

                pendulumX + pendulum.getLengthPendulum() * cos(pendulum.getAngle()),
                pendulumY - pendulum.getLengthPendulum() * sin(pendulum.getAngle()), 
                RED
                );


        // print mouse position
        std::cout << GetMouseX() << ' ' << GetMouseY() << '\n';
        DrawCircle(GetMouseX(), GetMouseY(), 2, RED);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}