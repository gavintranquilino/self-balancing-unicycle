#include <iostream>
#include <raylib.h>
#include <bruh.h>

int main()
{
    InitWindow(800, 600, "Raylib Window");

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();

    std::cout << "I spent 4+ hours trying to configure CMake and understand it btw\n"
              << "bin folder created? maybe?\n"
              << bruh::nah() << '\n';
    return 0;
}