/* Coding Assignment 5 */
// Nirajan P0kharel
// 1002068164

#include <stdio.h>
#include <stdlib.h>
#include "GameLib.h"
#include <string.h>

int main(void)
{
	char Phrase[MAX_INPUT] = {};
	char DashedPhrase[MAX_INPUT] = {};
	char UpperPhrase[MAX_INPUT] = {};
	int Strikes = 0;
	int i;

	StartGame(Phrase);

	DashIt(Phrase, DashedPhrase);

	for (i = 0; i < MAX_INPUT && Phrase[i] != '\0'; i++)
	{
		UpperPhrase[i] = toupper(Phrase[i]);
	}

	printf("\nHere's the phrase you need to guess\n");

	do
	{

		if (!GuessALetter(Phrase, DashedPhrase, UpperPhrase))
		{
			Strikes++;
			printf("\nStrike %d", Strikes);
		}
	}

	while (strchr(DashedPhrase, '-') && Strikes < STRIKES);

	if (Strikes < STRIKES)
	{
		printf("\n\nYou figured it out!!\n\nThe phrase was \n\n%s", Phrase);
		printf("\n\nYOU WIN!!!!\n");
	}
	else
	{
		printf("\n\n");
		printf("%d STRIKES - YOU'RE OUT!!\n\n", STRIKES);
		printf("Game over\n\n");
	}
	return 0;
}
