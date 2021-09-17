/*
*	Nick Waggoner
*	Programming in C
*	Due 4-30-2020
*	
*	Description:
*		This program prints out an array of string pointers
*		and then sorts the pointers before printing the strings
*		in order. Checks the first two characters in the words
*		to sort by alphabet before printing. Does not require user
*		input. Uses a bubble sort to organize the list of string 
*		pointers
* 
* Tags: pointers, sort, bubble sort, list
*/

#include <stdio.h> 
#include <stdlib.h> 

void printList(char *[], int);
void sortList(char *[], int);

int main(int argc, char ** argv) {
	
	int choice = 1;
	char*wordPtr[] = {"Eric", 
					  "Andrew", 
					  "Sean", 
					  "Daniel", 
					  "Trystan", 
					  "California",
					  "Alabama",
					  "Colorado",
					  "Uncle Eddy"};
	
	// calculates the size of the array. Allows the user to input more names into
	// array easily, or could be used for dynamically allocated memory (ie. Linked
	// List)
	int SIZE = sizeof(wordPtr) / sizeof(wordPtr[0]);
	
	printf("\nWelcome to Nick Waggoner's Sorting Strings program.");
	printf("\nThis program is designed to print out an array of words");
	printf("\nusing pointers and then bubble sorting the pointers in the");
	printf("\narray using a function, printing out the elements in");
	printf("\nsorted order without creating a memory leak by reassigning.");
	printf("the string literals.");	
	
	printf("\n\nNow printing all names in the array of string pointers");
	printf("\n------------------------------------------------------");
	printList(wordPtr, SIZE);
    
    printf("\n\nThe Program is now sorting the pointers based on element value.\n");
    sortList(wordPtr, SIZE);
    printf("\nThe program is now printing the array\n");
    printf("-------------------------------------");
    printList(wordPtr, SIZE);
    
    printf("\n\n\nSorting and printing is complete. Have a nice day.");
    
	return 0;
}

void printList(char *list[], int SIZE) {	
	//Prints out the values in the array
	for(int i = 0; i < SIZE; i++) {
		printf("\n%s", list[i]);
	}
}

void sortList(char *list[], int SIZE) {
	//Bubble sorts the pointers in the array
	char *temp = NULL;
	
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE-1; j++) {
			if((*list[i]) < (*list[j])) {
				//swap the pointers			
				temp = list[i];
				list[i] = list[j];
				list[j] = temp;
			}
			
			else if ((list[i][0]) == (list[j][0])) {
				//The first char is the same, check the second
				if((*list[i] + 1) < (*list[j] + 1)) {
					//swap the pointers 
					temp = list[i];
					list[i] = list[j];
					list[j] = temp;
				}
			}
			//Otherwise, they do nothing. Leave them alone; they're sorted
		}
	}
}
