// Nirajan Pokharel 1002068164
#include <stdio.h>
#include "GameLib.h"
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void StartGame(char ChosenPhrase[])  
{
	#include "PhraseBank.txt"  
	char DashPhrase[MAX_INPUT] = {};
	int i = 0;
	int Choice = 0;
		
	

	printf("\n\nWelcome to %d STRIKES - YOU'RE OUT - the CSE version\n\n", STRIKES);
	
	printf("Please pick a phrase from the following menu\n\n");
	
	
	while(strlen(PhraseBank[i]) > 0)
	{
		CheckPhrase(PhraseBank[i]);

		DashIt(PhraseBank[i], DashPhrase);
		printf("%d.\t%s\n", i, DashPhrase);
		i++;
	}
	
	printf("\nEnter choice : ");
	scanf("%d", &Choice);
	getchar();
	
	while(Choice < 1 || Choice > i)
	{
		printf("You entered an invalid choice.\nPlease reenter ");
		scanf("%d", &Choice);
	}
	
	strcpy(  ChosenPhrase , PhraseBank[Choice-1] ); 	
}

void CheckPhrase(char *Phrase)
{
	char *FindDash = NULL;
	FindDash = strchr(Phrase, '-');
	 if(FindDash != NULL)
	{
		printf("\n\"%s\" contains a dash in position %d!!\n", Phrase, abs(Phrase-FindDash)+1);
		printf("\nYou broke the rules.  We can't play.  BYE!!\n\n");
		exit(0);
	}
}

int GuessALetter(char Phrase[], char *DashedPhrase, char *UpperPhrase)
{
	char Guess;
	char *FindGuess = NULL;
	char UpperPhraseCopy[MAX_INPUT];
	int FoundALetter = 0;
	
	strcpy(UpperPhraseCopy, UpperPhrase);
		
	printf("\n\n%s", DashedPhrase);	
	printf("\n\nGuess a letter : ");
	scanf(" %c", &Guess);
	getchar();
	Guess = toupper(Guess);
	FindGuess = strchr(UpperPhraseCopy, Guess);
	while(FindGuess != NULL)  
	{
		FoundALetter = 1;
		DashedPhrase[FindGuess - UpperPhraseCopy] = Phrase[FindGuess - UpperPhraseCopy];
		*FindGuess = '-';

		FindGuess = strchr(UpperPhraseCopy, Guess);
	}
	
	return FoundALetter;
}

void DashIt(char Phrase[], char *DashPhrase)
{
	char *ReplaceIt;
	char Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int i = 0;
	for(i; Phrase[i] != '\0'; i++)
	{
		DashPhrase[i] = toupper(Phrase[i]);
	}
	DashPhrase[i] = 0;

	ReplaceIt = strpbrk(DashPhrase, Alphabet);
	while(ReplaceIt != NULL)
	{
		*ReplaceIt = '-';
		ReplaceIt = strpbrk(DashPhrase, Alphabet);
	}
}