#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "raylib.h"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h" // import ray's gui library
#include "_global.h"
#include "ExportSprite.h"
#include "DrawPixelGrid.h"
#include "Gui.h"

int main()
{
    InitWindow(screenWidth, screenHeight, "Artist");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        // Update
        UserInput();

        // Draw
        BeginDrawing();
        ClearBackground(GetColor(GuiGetStyle(DEFAULT, BACKGROUND_COLOR)));
        Gui();
        DrawPixelartGrid();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
