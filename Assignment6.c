/*
*	Nick Waggoner
*	Programming in C
*	Due 5-7-2020
*	
*	Description: This program opens a file that the user specifies
*	(by typing in the name of it), reads it, requests user input to
*	Append to the end of the file three times, and prints out the result
*	before freeing the MEM and exiting.
* 
* Tags: file i/o, pointers, path, user input, free memory, memory allocation
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 1024

int main(int argc, char ** argv) {
	
	FILE * filePtr = NULL;
	char fileName[50] = {};
	char * line = NULL;
	char * endOfFile = NULL;   
	char name[50] = "HOLD";   
	char garbage = '\0';
	
	line = (char *)malloc(sizeof(char)* MAX);
	
	//Ask the user for name of text file
	printf("What is the name of the file >> ");
	scanf("%s", fileName);
	
	//Read from text file if it exists
	
	if((filePtr = fopen(fileName,"r")) == NULL) {
		printf("%s does not exist.\n\n\n", fileName);
	}
	else {
		endOfFile = fgets(line, MAX, filePtr);
		
		while(endOfFile != NULL) {
			printf("%s",line);
			endOfFile = fgets(line, MAX, filePtr);
		}
		
		printf("\nEnd of File\n\n");
		fclose(filePtr);
	}
	
	//Open up the file to append
	for(int i = 0; i < 3; i++) {
		if((filePtr = fopen(fileName,"a")) == NULL) {
			printf("%s.ERROR404 - file not found",fileName);
		}
		else {
			printf("Please input a pun > ");
			if(i == 0) {
				scanf("%c", &garbage);
			}
			fgets(line, MAX, stdin);
			fprintf(filePtr, "%s", line);
			fclose(filePtr);
		
			printf("Finished Writing\n\n");
		}
	}
	
	//Open up the file to read it again
	if((filePtr = fopen(fileName,"r")) == NULL) {
		printf("%s does not exist.\n\n\n", fileName);
	}
	else {
		endOfFile = fgets(line, MAX, filePtr);
		while(endOfFile != NULL) {
			printf("%s",line);
			endOfFile = fgets(line, MAX, filePtr);
		}
		
		printf("\nEnd of File Printing. Have a nice Day!\n"
				"Thanks for a great Semester Pam!\n\n");
		fclose(filePtr);
	}
	
	//free Malloc'd memory before closing - good practice
	free(line);
	
	return 0;
}

