#include <iostream>
#include <raylib.h>
#include <bruh.h>


int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Simple Raylib Game");

    SetTargetFPS(60);

    Vector2 playerPosition = { static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 };
    float playerSpeed = 5.0f;

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) playerPosition.x += playerSpeed;
        if (IsKeyDown(KEY_LEFT)) playerPosition.x -= playerSpeed;
        if (IsKeyDown(KEY_DOWN)) playerPosition.y += playerSpeed;
        if (IsKeyDown(KEY_UP)) playerPosition.y -= playerSpeed;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        DrawText("Use arrow keys to move", 10, 10, 20, DARKGRAY);
        DrawCircleV(playerPosition, 20, MAROON);
        std::cout << '(' << playerPosition.x << " " << playerPosition.y << ')' << '\n';

        EndDrawing();
    }

    CloseWindow();
    return 0;
}