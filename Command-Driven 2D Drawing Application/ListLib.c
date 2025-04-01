/* ListLib-Template */
// Nirajan Pokharel 1002068164

#include "ListLib.h"

#include <string.h>
#include <stdlib.h>


void AddDrawCommandToList(char letter, char drawCommand[], NODE **linkedListHead)
{
    NODE *TempPtr, *NewNode;
	/* declare pointers of type NODE named TempPtr and NewNode */

	NewNode = (NODE*)malloc(sizeof(NODE)); 
    NewNode->Letter = letter;
    NewNode->DrawCommand = (char*)malloc(strlen(drawCommand) + 1); 
    strcpy(NewNode->DrawCommand, drawCommand); 
    NewNode->next_ptr = NULL;
    
	/* malloc a new node and assign the Letter and the DrawCommand (after mallocing memory for it) */

	 if (*linkedListHead == NULL)
    { 
    
        *linkedListHead = NewNode;
    }
    else 
    { 
    
        TempPtr = *linkedListHead;
        while (TempPtr->next_ptr != NULL) 
		{
            TempPtr = TempPtr->next_ptr;
        }
        TempPtr->next_ptr = NewNode;
    }

	/* If the LinkedListHead is NULL, then give it the address of the new node */
	/* Else traverse to the end of the linked list and add the new node */
}

NODE* FindLetter(NODE *linkedListHead, char letter, char DC[])
{
	/* while traversing the linked list AND the Letter in the node is not the Letter passed in */

	NODE* TempPtr = linkedListHead;
	while (TempPtr != NULL && TempPtr->Letter != letter)
	{
		TempPtr = TempPtr->next_ptr;
	}

	if ( TempPtr != NULL)
	{
		strcpy(DC, TempPtr->DrawCommand); 
        return TempPtr->next_ptr;
		/* copy the DrawCommand from the node into the passed in parameter */
		/* return the next pointer stored in TempPtr */
	}
	else
	{
		memset(DC, '\0', sizeof(*DC));  //Set DC to NULLs to signal that we found all of the nodes for this letter
		return TempPtr;
	}
}