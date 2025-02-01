#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <raylib.h>
#include "ExportSprite.h"
#include "DrawPixelGrid.h"

extern char TextBox001Text[128];
extern Color colors[GRID_SIZE][GRID_SIZE];

char *c_dest_file = "../export/RENAMETOLABELNAME.c";
char *h_dest_file = "../export/RENAMETOLABELNAME.h";

void ExportSprite()
{
    // append files
    FILE *dest_appendhfile = fopen(h_dest_file, "ab");
    if (dest_appendhfile != NULL)
    {
        fprintf(dest_appendhfile, "#ifndef ");
        fprintf(dest_appendhfile, "%s", TextBox001Text);
        fprintf(dest_appendhfile, "_H\n");
        fprintf(dest_appendhfile, "#define ");
        fprintf(dest_appendhfile, "%s", TextBox001Text);
        fprintf(dest_appendhfile, "_H\n");
        fprintf(dest_appendhfile, "\n");
        fprintf(dest_appendhfile, "#define ");
        fprintf(dest_appendhfile, "%s", TextBox001Text);
        fprintf(dest_appendhfile, "Bank 0\n");
        fprintf(dest_appendhfile, "\n");
        fprintf(dest_appendhfile, "extern const unsigned char ");
        fprintf(dest_appendhfile, "%s", TextBox001Text);
        fprintf(dest_appendhfile, "[];\n");
        fprintf(dest_appendhfile, "\n");
        fprintf(dest_appendhfile, "#endif\n");
        fclose(dest_appendhfile);
        printf("Appended to file: %s\n", h_dest_file);
    }
    else
    {
        printf("Failed to open file: %s\n", h_dest_file);
    }

    FILE *dest_appendcfile = fopen(c_dest_file, "ab");
    if (dest_appendcfile != NULL)
    {
        fprintf(dest_appendcfile, "const unsigned char ");
        fprintf(dest_appendcfile, "%s", TextBox001Text);
        fprintf(dest_appendcfile, "[] =\n");
        fprintf(dest_appendcfile, "{\n");

        for (int y = 0; y < GRID_SIZE; y++)
        {
            for (int x = 0; x < GRID_SIZE; x++)
            {
                Color color = colors[y][x];
                unsigned char hexValue = (color.r & 0xE0) | ((color.g & 0xE0) >> 3) | ((color.b & 0xC0) >> 6);
                fprintf(dest_appendcfile, "0x%02X", hexValue);

                if (x < GRID_SIZE - 1)
                {
                    fprintf(dest_appendcfile, ", ");
                }
            }
            fprintf(dest_appendcfile, ",\n");
        }

        fprintf(dest_appendcfile, "};\n");
        fclose(dest_appendcfile);
        printf("Appended to file: %s\n", c_dest_file);
    }
    else
    {
        printf("Failed to open file: %s\n", c_dest_file);
    }

    printf("Exporting sprite as GBDK C and header file\n");
    mkdir("../export", 0777);
}