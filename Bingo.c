//NIRAJAN POKHAREL - 1002068164

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fillbingocard(int card[5][5]);
void printbingocard(int card[5][5]);
int picknumber(int usednumbers[75], int counter);
int checknumber(int number, int card[5][5]);
int checkrow(int card[5][5]);
int checkcolumn(int card[5][5]);
int checkdiagonal(int card[5][5]);



void fillbingocard(int card[5][5])
{
    for(int i=0; i<5; i++)
    {
        int duparray[5] = {0};
        for(int j=0; j<5; j++)
        {
            int randNum = rand() % 15 +(15*i) +1;

            for(int l=0; l<5; l++)
            {
                while(randNum == duparray[l])
                {
                    randNum = rand() % 15 +(15*i) +1;
                    l =-1;
                }
            }
            card[j][i] = randNum;
            duparray[j] = randNum;
        }
    }
    card[2][2] = 0;
}


void printbingocard(int bingocard[5][5])
{
    char format[]="----------------------------------------";
    printf("\n");
    printf("\t B\t\t I\t\t N\t\t G\t\t O\n");
    printf("%s%s-\n",format, format);
    
    for (int i=0;i<5;i++)
    {    
        printf("|");
        for (int j=0;j<5;j++)
        {
            if (bingocard[i][j]==0)
                printf("\t%2c\t|", bingocard[i][j] + 88);
            else
                printf("\t%2d\t|",bingocard[i][j]);
        }
        printf("\n%s%s-\n",format, format);


    }  
    return;
}

int picknumber(int usednumbers[75], int counter) 
{   
    int picked = 0;
    int number;

    number = rand()%75+1;
    
    for (int i = 0; i < counter; i++)
    {
        if (number == usednumbers[i])
        {
            number = rand()%75+1;
            i = -1;
        }
    }
    usednumbers[counter] = number;
    
    if(number >= 1 && number <= 15)
    {
        printf("\nThe next number is B%d\n", number);
    }
    else if(number >= 16 && number <= 30)
    {
        printf("The next number is I%d\n", number);
    } 
    else if(number >= 31 && number <= 45)
    {
        printf("The next number is N%d\n", number);
    }
    else if(number >= 46 && number <= 60)
    {
        printf("The next number is G%d\n", number);
    }
    else if(number >= 61 && number <= 75)
    {
        printf("The next number is O%d\n", number);
    }

    return number;
    
}

int checknumber(int number, int card[5][5])
{
    int found = 0;
    for(int i = 0; i < 5; i++) 
    {
        for(int j = 0; j < 5; j++)
        {
            if (card[i][j] == number) 
            {
                card[i][j] = 0;
                found = 1;
            }
        }
    }
    return found;
}

int checkrow(int card[5][5])
{
    int completed = 0;
    for (int i = 0; i < 5; i++) 
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += card[i][j];
        }
        if (sum == 0) 
        {
            completed = 1;
            i=5;
        }
    }
    return completed;
}


int checkcolumn(int card[5][5]) // Function to check for completed column in the bingo array
{
    int completed = 0;
    for (int i = 0; i < 5; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += card[j][i];
        }
        if (sum == 0) 
        {
            completed = 1;
            i = 5;
        }
    }
    return completed;
}


int checkdiagonal(int card[5][5]) // Function to check for completed diagonal in the bingo array
{
    int completed = 0;
    int sum = 0;
    for (int i = 0; i < 5; i++) 
    {
        sum += card[i][i];
    }
    if (sum == 0) 
    {
        completed = 1;
    } else 
    {
        sum = 0;
        for (int i = 0; i < 5; i++) 
        {
            sum += card[i][4-i];
        }
        if (sum == 0)
        {
            completed = 1;
        }
    }
    return completed;
}

int main()
{
    srand(time(0));

    int bingo[5][5];
    int usednumbers[75] = {0};
    int count = 0;

    int checkBingo;
    fillbingocard(bingo);// Call function to fill bingo card

  
    printbingocard(bingo);  // Call function to print bingo card to screen
    
    while (checkrow(bingo) == 0 && checkcolumn(bingo) == 0 && checkdiagonal(bingo) == 0) 
    {
       
        int number = picknumber(usednumbers, count);
        count++;

        
        printf("\nDo you have it? (Y/N) ");// Show the player the number (including the B, I, N, G or O) and ask if the player has on their bingo card.
        char answer;
        scanf(" %c", &answer);
        
        if (answer == 'Y')
        {
            int found = checknumber(number, bingo);
            printbingocard(bingo);  
            if (!found) 
            {
                printf("That value is not on your BINGO card - are you trying to cheat??\n");
            }
        }
        else
        {
            printbingocard(bingo);
        }
        


        // Call a function to check for a completed row and/or column and/or diagonal.
        checkBingo = checkrow(bingo) || checkcolumn(bingo) || checkdiagonal(bingo);

        if (checkBingo == 1)
        {    
            if (checkrow(bingo) == 1 && checkcolumn(bingo) == 1)
            {
                printf("You filled out a row and a column - BINGO!!!");
            }
            else
            {
                if( checkrow(bingo) == 1)
                {
                    printf("You filled out a row - BINGO!!! ");
                }
                else if( checkcolumn(bingo) == 1)
                {
                    printf("You filled out a column - BINGO!!! ");
                } 
                else if(checkdiagonal(bingo))
                 {
                    printf("You filled out a diagonal - BINGO!!! ");
                }
                    
            }
        }
        
    }

    return 0;
}