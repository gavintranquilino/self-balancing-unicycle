#include <iostream>
#include <cmath>

#include <raylib.h>

#include <bruh.h>
#include <invertedpendulum.h>

int main() 
{
    const int screenWidth = 800;
    const int screenHeight = 450;

    // MMGS, millimeters, grams, seconds
    double timeInterval = 0.01;
    double massBase = 50;
    double massPendulum = 50;
    double lengthPendulum = 10;
    double xPos = 0;
    double angle = 0;
    double xVel = 0;
    double angleVel = 0;
    double xAccel = 0;
    double angleAccel = 0;
    double appliedForce = 0;
    double timeElapsed = 0;

    InvertedPendulum pendulum(timeInterval, massBase, massPendulum, lengthPendulum, xPos, angle, xVel, angleVel, xAccel, angleAccel, appliedForce, timeElapsed);
    
    InitWindow(screenWidth, screenHeight, "Inverted Pendulum");

    SetTargetFPS(60);

    std::cout << MASS_BASE << ' ' << MASS_PENDULUM << ' ' << LENGTH_PENDULUM << '\n';

    // ----- Main game loop -----
    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}