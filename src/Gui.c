
#include "raygui.h"
#include "Gui.h"
#include "_global.h"
#include "ExportSprite.h"

char TextBox001Text[128] = "ExampleLabel";
char TextBox002Text[128] = "Export sprite as GBDK C file";
char TextBox003Text[128] = "";

bool TextBox001EditMode = false;
bool Button002Pressed = false;
bool Spinner003EditMode = false;

int Spinner003Value = 3;
void Gui()
{
    // export sprite name
    if (GuiTextBox((Rectangle){screenWidth - 184, 24, 160, 24}, TextBox001Text, 128, TextBox001EditMode))
        TextBox001EditMode = !TextBox001EditMode;

    // export sprite as GBDK C file button
    Button002Pressed = GuiButton((Rectangle){screenWidth - 184, 56, 160, 24}, TextBox002Text);
    if (Button002Pressed)
        {
            ExportSprite();
        }

    // color picker
    if (GuiSpinner((Rectangle){screenWidth - 184, 88, 160, 24}, TextBox003Text, &Spinner003Value, 0, 3, Spinner003EditMode))
        Spinner003EditMode = !Spinner003EditMode;
}