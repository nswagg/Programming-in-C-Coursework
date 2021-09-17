/*
*	Nick Waggoner
*	Programming in C
*	Due 4-16-2020
*	
*	Description:
*		This program builds an ordered singly-linked list from user inputs
*		greater than 0 using struct listNodes. The program allocates memory for
*		thelistNode and then assigns the user-inputted data (an integer) into
*		the list. The program then prints the numbers in the list and frees
*		thelistNodes
* 
* Tags: linked list, memory allocation, pointers, struct, free, free memory
*/
#include <stdio.h> 
#include <stdlib.h> 
  
/* Link listlistNode */
struct listNode { 
    int data; 
    struct listNode* next; 
}; 

// Global struct listNode header
struct listNode *header = {0};

//function prototypes
void createNode(int);
void insert(struct listNode *);
void printList(void);
void freeList(void);

int main() { 
    int choice = 1;
    
    //header
    printf("\nWelcome to Nick Waggoner's Ordered Linked List program.");
    printf("\nThis program is designed to build an ordered linked list of");
    printf("\nnumbers greater than zero and sort them for the user before printing");
    printf("\nthe list. It also makes sure the list is freed before exiting.");
    printf("\nstruct listNodes are used to create the list with pointers to");
    printf("\nthe head and current location.\n\n");
    
    while (choice > 0) {
    	printf("\nPlease insert a number greater than zero into the list >> ");
    	scanf("%d", &choice);
    	
    	//double checks condition
    	if(choice >0) {
    		createNode(choice);
		}
	}

    printf("\n\nCreated Linked List\n"); 
    printList();
    
	freeList(); 
    return 0; 
}// main

    //Allocates memory for struct listNode
void createNode(int new_data) { 

    struct listNode* newNode = (struct listNode*) malloc(sizeof(struct listNode)); 
	  
    //Assigns data to the struct listNode
    newNode->data  = new_data; 
    newNode->next =  NULL; 
  
    insert(newNode); 
}// createNode

//function to insert alistNode in the linked list. Active sort
void insert(struct listNode *newNode) { 
    struct listNode* current = newNode;

    /* Special case for the head end */
    if (header == NULL || (header)->data >= newNode->data) { 
        newNode->next = header; 
        header = newNode; 
    } 
    else {
        // Locates the  struct listNode before the point of insertion 
        // through incrementation
		        
        current = header; //starts it at the beginning of the list
        while (current->next!=NULL && current->next->data < newNode->data) { 
            current = current->next; 
        } 
        
        newNode->next = current->next; 
        current->next = newNode; 
    } 
    
}// insert
  
/* Function to print linked list */
void printList() { 
    struct listNode *current = header; 
    
    while(current != NULL) { 
        printf("%d  ", current->data); 
        current = current->next; 
    } 
}// printList

void freeList() {
	struct listNode *temp = header;
	struct listNode *current;
	
	// Can't free header
	while(temp != header) {
		current = temp->next;
		free(temp);
		temp = current;
	}
}// freeList
