#include <iostream>
#include <cmath>

#include <raylib.h>

#include <bruh.h>
#include <invertedpendulum.h>

int main() {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 450;

    InvertedPendulum::InvertedPendulum pendulum;
    InitWindow(screenWidth, screenHeight, "Inverted Pendulum");

    SetTargetFPS(60);

    // Main loop
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(WHITE);
        EndDrawing();
    }

    // Cleanup
    CloseWindow();

    return 0;
}