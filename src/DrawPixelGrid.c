#include "raylib.h"
#include "DrawPixelGrid.h"

Color PixelColor1 = PURPLE;
Color PixelColor2 = PURPLE;
Color PixelColor3 = PURPLE;
Color PixelColor4 = PURPLE;
Color PixelColor5 = PURPLE;
Color PixelColor6 = PURPLE;
Color PixelColor7 = PURPLE;
Color PixelColor8 = PURPLE;
Color PixelColor9 = PURPLE;
Color PixelColor10 = PURPLE;
Color PixelColor11 = PURPLE;
Color PixelColor12 = PURPLE;
Color PixelColor13 = PURPLE;
Color PixelColor14 = PURPLE;
Color PixelColor15 = PURPLE;
Color PixelColor16 = PURPLE;
Color PixelColor17 = PURPLE;
Color PixelColor18 = PURPLE;
Color PixelColor19 = PURPLE;
Color PixelColor20 = PURPLE;
Color PixelColor21 = PURPLE;
Color PixelColor22 = PURPLE;
Color PixelColor23 = PURPLE;
Color PixelColor24 = PURPLE;
Color PixelColor25 = PURPLE;
Color PixelColor26 = PURPLE;
Color PixelColor27 = PURPLE;
Color PixelColor28 = PURPLE;
Color PixelColor29 = PURPLE;
Color PixelColor30 = PURPLE;
Color PixelColor31 = PURPLE;
Color PixelColor32 = PURPLE;
Color PixelColor33 = PURPLE;
Color PixelColor34 = PURPLE;
Color PixelColor35 = PURPLE;
Color PixelColor36 = PURPLE;
Color PixelColor37 = PURPLE;
Color PixelColor38 = PURPLE;
Color PixelColor39 = PURPLE;
Color PixelColor40 = PURPLE;
Color PixelColor41 = PURPLE;
Color PixelColor42 = PURPLE;
Color PixelColor43 = PURPLE;
Color PixelColor44 = PURPLE;
Color PixelColor45 = PURPLE;
Color PixelColor46 = PURPLE;
Color PixelColor47 = PURPLE;
Color PixelColor48 = PURPLE;
Color PixelColor49 = PURPLE;
Color PixelColor50 = PURPLE;
Color PixelColor51 = PURPLE;
Color PixelColor52 = PURPLE;
Color PixelColor53 = PURPLE;
Color PixelColor54 = PURPLE;
Color PixelColor55 = PURPLE;
Color PixelColor56 = PURPLE;
Color PixelColor57 = PURPLE;
Color PixelColor58 = PURPLE;
Color PixelColor59 = PURPLE;
Color PixelColor60 = PURPLE;
Color PixelColor61 = PURPLE;
Color PixelColor62 = PURPLE;
Color PixelColor63 = PURPLE;
Color PixelColor64 = PURPLE;

Color WhiteColor = WHITE;
Color BlackColor = BLACK;
Color GrayColor = GRAY;
Color currentColor = GRAY;
Color colors;

extern int Spinner003Value;

void DrawPixelartGrid()
{
    // define colors for the grid squares
    Color colors[GRID_SIZE][GRID_SIZE] = {
        {PixelColor1, PixelColor2, PixelColor3, PixelColor4, PixelColor5, PixelColor6, PixelColor7, PixelColor8},
        {PixelColor9, PixelColor10, PixelColor11, PixelColor12, PixelColor13, PixelColor14, PixelColor15, PixelColor16},
        {PixelColor17, PixelColor18, PixelColor19, PixelColor20, PixelColor21, PixelColor22, PixelColor23, PixelColor24},
        {PixelColor25, PixelColor26, PixelColor27, PixelColor28, PixelColor29, PixelColor30, PixelColor31, PixelColor32},
        {PixelColor33, PixelColor34, PixelColor35, PixelColor36, PixelColor37, PixelColor38, PixelColor39, PixelColor40},
        {PixelColor41, PixelColor42, PixelColor43, PixelColor44, PixelColor45, PixelColor46, PixelColor47, PixelColor48},
        {PixelColor49, PixelColor50, PixelColor51, PixelColor52, PixelColor53, PixelColor54, PixelColor55, PixelColor56},
        {PixelColor57, PixelColor58, PixelColor59, PixelColor60, PixelColor61, PixelColor62, PixelColor63, PixelColor64}};

    // draw the grid
    for (int y = 0; y < GRID_SIZE; y++)
    {
        for (int x = 0; x < GRID_SIZE; x++)
        {
            DrawRectangle(24 + x * SQUARE_SIZE, 24 + y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE, colors[y][x]);
        }
    }
}

void UserInput()
{
    if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
    {
        int MouseX = GetMouseX();
        int MouseY = GetMouseY();

        int GridX = (MouseX - 24) / SQUARE_SIZE;
        int GridY = (MouseY - 24) / SQUARE_SIZE;

        // Set the current color based on the spinner value
        if (Spinner003Value == 0)
        {
            currentColor = PURPLE;
        }
        else if (Spinner003Value == 1)
        {
            currentColor = WHITE;
        }
        else if (Spinner003Value == 2)
        {
            currentColor = GRAY;
        }
        else if (Spinner003Value == 3)
        {
            currentColor = BLACK;
        }

        if (GridX >= 0 && GridX < GRID_SIZE && GridY >= 0 && GridY < GRID_SIZE)
        {
            // update the color of the clicked pixel
            Color *pixelColors[GRID_SIZE * GRID_SIZE] = {
                &PixelColor1, &PixelColor2, &PixelColor3, &PixelColor4, &PixelColor5, &PixelColor6, &PixelColor7, &PixelColor8,
                &PixelColor9, &PixelColor10, &PixelColor11, &PixelColor12, &PixelColor13, &PixelColor14, &PixelColor15, &PixelColor16,
                &PixelColor17, &PixelColor18, &PixelColor19, &PixelColor20, &PixelColor21, &PixelColor22, &PixelColor23, &PixelColor24,
                &PixelColor25, &PixelColor26, &PixelColor27, &PixelColor28, &PixelColor29, &PixelColor30, &PixelColor31, &PixelColor32,
                &PixelColor33, &PixelColor34, &PixelColor35, &PixelColor36, &PixelColor37, &PixelColor38, &PixelColor39, &PixelColor40,
                &PixelColor41, &PixelColor42, &PixelColor43, &PixelColor44, &PixelColor45, &PixelColor46, &PixelColor47, &PixelColor48,
                &PixelColor49, &PixelColor50, &PixelColor51, &PixelColor52, &PixelColor53, &PixelColor54, &PixelColor55, &PixelColor56,
                &PixelColor57, &PixelColor58, &PixelColor59, &PixelColor60, &PixelColor61, &PixelColor62, &PixelColor63, &PixelColor64};

            *pixelColors[GridY * GRID_SIZE + GridX] = currentColor;
        }
    }
}