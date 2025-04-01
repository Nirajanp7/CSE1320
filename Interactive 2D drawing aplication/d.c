//Nirajan Pokharel 

#include <stdio.h>
#include "DrawTool.h"
#include <stdlib.h>
#include <ctype.h> //for using toupper()
#include <string.h>

int main()
{

    int MyMapSize;
    char Map[MAXMAPSIZE][MAXMAPSIZE];
    InitializeMap(Map, &MyMapSize);
    PrintInstructions();
    PrintMap(Map, MyMapSize);

    char Array[20];

    char draw_command[20];

    int y, x, count;
    char *N = NULL;

    printf("Enter draw command (Enter Q to Quit) :  "); // Prompt user for input
    fgets(Array, 20, stdin);

    N = strtok(Array, "(),");
    strcpy(draw_command, N);
    draw_command[0] = toupper(draw_command[0]); // makes every character capital

    while (draw_command[0] != 'Q')
    {
        N = strtok(NULL, "(),");
        y = atoi(N);
        N = strtok(NULL, "(),");
        x = atoi(N);
        N = strtok(NULL, "(),");
        count = atoi(N);

        N = strtok(NULL, "(),");
        char mark[20];
        strcpy(mark, N);
        if (mark[0] == '\n')
        {
            mark[0] = 'X';
        }

        if (draw_command[0] == 'P' || draw_command[0] == 'V' || draw_command[0] == 'H')
        {
            if (draw_command[0] == 'P')
            {
                if (x < 0 || x >= MyMapSize || y < 0 || y >= MyMapSize)
                {
                    printf("\nThat draw command is out of range\n");
                    PrintMap(Map, MyMapSize);
                }
                else
                {
                    Map[y][x] = mark[0];
                    PrintMap(Map, MyMapSize);
                }
            }
            else if (draw_command[0] == 'H')
            {
                if (x < 0 || x >= MyMapSize || y < 0 || y >= MyMapSize || count > (MyMapSize - x))
                {
                    printf("\nThat draw command is out of range\n");
                    PrintMap(Map, MyMapSize);
                }
                else
                {
                    DrawLine(Map, y, x, draw_command[0], count, mark[0]);
                    PrintMap(Map, MyMapSize);
                }
            }
            else
            {
                if (x < 0 || x >= MyMapSize || y < 0 || y >= MyMapSize || count > (MyMapSize - y))
                {
                    printf("\nThat draw command is out of range\n");
                    PrintMap(Map, MyMapSize);
                }
                else
                {
                    DrawLine(Map, y, x, draw_command[0], count, mark[0]);
                    PrintMap(Map, MyMapSize);
                }
            }
        }
        else
        {
            printf("The draw command is invalid!!!\n");
        }

        printf("Enter draw command (Enter Q to Quit)\n  "); // Prompt user for input
        fgets(Array, 20, stdin);

        N = strtok(Array, "(),");
        strcpy(draw_command, N);
        draw_command[0] = toupper(draw_command[0]); // makes every character capital
    }
}