// FileLib Template
//Nirajan Pokharel 1002068164

#include <stdio.h>
#include <string.h>

#include "DrawTool.h"
#include "ListLib.h"
#include "FileLib.h"

FILE *OpenFile(int argc, char *argv[])
{	
	/* declare various variables needed */
	FILE* DCFile;
	char filename[200];



	/* if argc is 2, then use argv[1] as the input file name, else print the message seen in sample output */
	if (argc == 2)
	{
		strcpy(filename, argv[1]);
	}
	else
	{
		printf("Must be run with run file\n");
		printf("Enter the input file name ");
		scanf("%s", filename);
	}
	
	

	do
	{
		DCFile = fopen(filename, "r");
		/* open file with "r" mode */
		if (DCFile == NULL)
		/* if file did not open */
		{
			printf("Could not open input file\n");
			printf("Enter a file name at the prompt ");
			scanf("%s", filename);
		}
	}
	while (DCFile == NULL);

	/* return the file handle */
	return DCFile;
}

void ReadFileIntoLinkedList(FILE *DCFile, NODE **LinkedListHead)
{
	/* declare various variables needed */
	char line[256], *token,letter, drawCommand[777] ;

	
	while (fgets(line, sizeof(line), DCFile))
	{
		/* if line from file ends with \n, then replace \n with \0 */
		if (line[strlen(line) - 1] == '\n')
        {
            line[strlen(line) - 1] = '\0';
        }
		
		/* tokenize to get the Letter and the DrawCommand */
		token = strtok(line, "|");
        letter = token[0];
        token = strtok(NULL, "|");
        strcpy(drawCommand, token);
	
		/* Call AddDrawCommandToList with correct parameters */
		AddDrawCommandToList(letter, drawCommand, LinkedListHead);
	}
}