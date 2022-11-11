// linkedListPrepend.c - Demo program to illustrate linked lists
#include <stdio.h>   // For printf and scanf
#include <stdlib.h>  // For malloc


typedef struct Node *NodePtr;  // Make:  NodePtr to be a synonym for: struct Node *
struct Node {
    int data;        // The data stored at the node
    NodePtr pNext;   // Pointer to the next node
};


//------------------------------------------------------------
// Consider: Does this function destroy the head node pointer?
void displayList( NodePtr pHead)
{
   printf("List is: ");
   while( pHead != NULL) {
      printf("%d ", pHead->data);
      pHead = pHead->pNext;
   }
   printf("\n");
} // end displayList()


//--------------------------------------------------------------
// Prepend number at the beginning of the list
void prependNumber( NodePtr *pHead, int number)
{
    // Allocate space for new node and initialize it
    NodePtr pTemp;     // pointer to new Node
    pTemp = malloc( sizeof( struct Node));
    pTemp->data = number;
    pTemp->pNext = *pHead;
    
    // Prepend at head of list
    *pHead = pTemp;
} // end prependNumber()


//--------------------------------------------------------------
// Delete the first Node on the list and return the number that was in it.
int deleteNumber( NodePtr *pHead)
{
    // Sanity check: Ensure there is at least one Node on the list
    if( *pHead == NULL) {
        printf("Sorry, can't delete from an empty list. \n");
        return -1;
    }
    
    // Point to node to be deleted
    NodePtr pNodeToDelete = *pHead;  // Pointer to node to be deleted
    int value = (*pHead)->data;   	// Retrieve value from node to be deleted
    *pHead = (*pHead)->pNext;     	// Advance head pointer
    free( NodeToDelete);             // Free up memory from old node
    
    return value;                 	// Return the value from the deleted Node
} // end deleteNumber()


//--------------------------------------------------------------
// Consider: For input of 1 3 5 -1, what is the output?
int main()
{
    NodePtr pHead = NULL;   // head of linked list
    int number = 0;         // Used to store numbers read in
    char menuOption = ' ';  // Store user input menu option
    
    // Loop to allow adding and deleting list values.
    while( menuOption != 'x') {
        printf("Menu: \n");
        printf("  a n  to add value n to the list \n");
        printf("  d    to delete value from the list \n");
        printf("  x    to exit program \n");
        printf("Your choice: ");
        scanf(" %c", &menuOption);

		// Handle menu options
        switch (menuOption) {
            case 'x': return 0;   			// Exit program
                      break;
            case 'a': scanf("%d", &number);  // Read in the number to be added
                      prependNumber( &pHead, number); // Prepend to front of list
                      break;
            case 'd': number = deleteNumber( &pHead); // Delete from front of list
                      if( number != -1) {
                            printf("Deleted %d\n", number);
                      }
                      break;
            default:  printf("Invalid menu option.  Retry. \n");
                      continue;
        }
        
        printf("\n");
        displayList( pHead);
    }

    return 0;         // return value to keep C++ happy
} // end main()

