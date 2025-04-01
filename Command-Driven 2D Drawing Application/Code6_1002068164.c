// Nirajan Pokharel   1002068164

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> //for using toupper()
#include <string.h>
#include "DrawTool.h"
#include "ListLib.h"
#include "FileLib.h"

int main(int argc, char *argv[])
{

    char Input_Letter[7];
    char Array[MAXMAPSIZE][MAXMAPSIZE] = {};
    NODE *LinkedListHead = NULL;
    NODE *tmpptr = LinkedListHead;
    FILE *fp = NULL;
    fp = OpenFile(argc, argv);
    ReadFileIntoLinkedList(fp, &LinkedListHead);
    InitializeMap(Array);
    char Draw_command[40] = {};
    char *N = NULL;
    char draw_command[20] = {};
    int from, to, count;

    printf("Enter 1-3 letter ");
    scanf("%s", Input_Letter);

    while (strlen(Input_Letter) > 3 || strlen(Input_Letter) < 1)
    {
        printf("Enter 1-3 letter");
        scanf("%s", Input_Letter);
    }

    for (int i = 0; i < 3; i++)
    {
        Input_Letter[i] = toupper(Input_Letter[i]);

        FindLetter(LinkedListHead, Input_Letter[i], Draw_command);
        tmpptr = FindLetter(LinkedListHead, Input_Letter[i], Draw_command);

        while (strlen(Draw_command) > 0)
        {
            N = strtok(Draw_command, "(),");
            strcpy(draw_command, N);

            N = strtok(NULL, "(),");
            from = atoi(N);
            N = strtok(NULL, "(),");
            to = atoi(N);
            N = strtok(NULL, "(),");
            count = atoi(N);

            N = strtok(NULL, "(),");
            char mark[20] = {};
            strcpy(mark, N);
            if (mark[0] == '\n')
            {
                mark[0] = 'X';
            }

            if (i == 1)
            {
                to = to + 7;
            }
            else if (i == 2)
            {
                to = to + 14;
            }

            if (draw_command[0] == 'P' || draw_command[0] == 'V' || draw_command[0] == 'H')
            {
                if (draw_command[0] == 'P')
                {
                    Array[from][to] = mark[0];
                }
                else if (draw_command[0] == 'H')
                {

                    DrawLine(Array, from, to, draw_command[0], count, mark[0]);
                }
                else
                {

                    DrawLine(Array, from, to, draw_command[0], count, mark[0]);
                }
            }
            else
            {
                printf("The draw command is invalid!!!\n");
            }
            FindLetter(tmpptr, Input_Letter[i], Draw_command);
            tmpptr = FindLetter(tmpptr, Input_Letter[i], Draw_command);
            
        }
    }
    PrintMap(Array);
}
