#include <iostream>
#include <raylib.h>
#include <bruh.h>

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Simple Raylib Game");

    SetTargetFPS(60);

    Vector2 playerPosition = { static_cast<float>(screenWidth) / 2, static_cast<float>(screenHeight) / 2 };
    float playerSpeed = 15.0f;
    int playerRadius = 20;

    Vector2 playerVelocity = { 0.0f, 0.0f };
    float playerAcceleration = 0.5f;
    float playerMaxSpeed = 10.0f;
    float playerFriction = 0.96f;

    bool isGrounded = false;
    float gravity = 0.5f;
    float jumpForce = 15.0f;

    Rectangle ground = { 0, static_cast<float>(screenHeight) - 40, static_cast<float>(screenWidth), 40 };

    // Create the player trail array
    Vector2 playerTrail[10] = { 0 };
    Color trailColor = MAROON;

    Rectangle platform = { screenWidth / 2 - 100, screenHeight / 2, 200, 20 };

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_RIGHT)) playerVelocity.x += playerAcceleration;
        if (IsKeyDown(KEY_LEFT)) playerVelocity.x -= playerAcceleration;

        if (IsKeyPressed(KEY_UP) && isGrounded) {
            playerVelocity.y -= jumpForce;
            isGrounded = false;
        }

        playerVelocity.y += gravity;

        if (playerVelocity.x > playerMaxSpeed) playerVelocity.x = playerMaxSpeed;
        if (playerVelocity.x < -playerMaxSpeed) playerVelocity.x = -playerMaxSpeed;

        playerVelocity.x *= playerFriction;

        playerPosition.x += playerVelocity.x;
        playerPosition.y += playerVelocity.y;

        if (playerPosition.y >= ground.y - playerRadius) {
            playerPosition.y = ground.y - playerRadius;
            playerVelocity.y = 0;
            isGrounded = true;
        }

        if (playerPosition.x >= platform.x && playerPosition.x <= platform.x + platform.width &&
            playerPosition.y >= platform.y - playerRadius) {
            playerPosition.y = platform.y - playerRadius;
            playerVelocity.y = 0;
            isGrounded = true;
        }

        if (playerPosition.x >= screenWidth - playerRadius) playerPosition.x = screenWidth - playerRadius;
        if (playerPosition.x <= playerRadius) playerPosition.x = playerRadius;

        // Update player trail
        for (int i = 9; i > 0; i--) {
            playerTrail[i] = playerTrail[i - 1];
        }
        playerTrail[0] = playerPosition;

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw platforms
        DrawRectangleRec(platform, BLUE);
        DrawRectangleRec(ground, GRAY);

        // Draw player trail
        // for (int i = 0; i < 10; i++) {
        //     float alpha = (i + 1) * 255 / 10.0f;
        //     DrawCircleV(playerTrail[i], playerRadius, Fade(trailColor, alpha));
        // }

        // at player position, draw a yellow equalateral triangle and black triangular glasses
        DrawTriangle(playerPosition, { playerPosition.x - 20, playerPosition.y + 20 }, { playerPosition.x + 20, playerPosition.y + 20 }, YELLOW);
        // outline the yellow triangle with black lines
        DrawTriangleLines(playerPosition, { playerPosition.x - 20, playerPosition.y + 20 }, { playerPosition.x + 20, playerPosition.y + 20 }, BLACK);
        DrawTriangle(playerPosition, { playerPosition.x - 20, playerPosition.y + 20 }, { playerPosition.x - 10, playerPosition.y + 20 }, BLACK);
        DrawTriangle(playerPosition, { playerPosition.x + 20, playerPosition.y + 20 }, { playerPosition.x + 10, playerPosition.y + 20 }, BLACK);

        // DrawCircleV(playerPosition, playerRadius, MAROON);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
