/*	
*	Nick Waggoner
*	Programming in C
*	Due: 3-12-2020
*
*	Description: This program inputs two values from the user and sends them
*	to the correct function which is specified by the user after seeing the
*	menu. Their selection calls the correct function using an array of function
*	pointers and sends the values to it in pass by reference.
* 
* Tags: functions, pointers, array, algebra
*/

#include <stdio.h>

//function prototypes:
double add(double *value0, double *value1);
double subtract(double *value0, double *value1);
double multiply(double *value0, double *value1);
double divide(double *value0, double *value1);

int main(int argv, char ** argc)
{
	double value0 = 0;
	double value1 = 0;
	int pick = 0;
	int choice = 1;	//set to add by default	
	
	//initializes array of functions for calling
	double (*functionPtr[])(double*, double*) = {add, subtract, multiply, divide};
	
	//Header
	printf("\nWelcome to Nick Waggoner's simple Calculator program");
	printf("\nThis program takes in two user values and performs the");
	printf("\ndesignated operation indicated by the user.");
	
	while(choice != 0) {
		//Scans for user input and stores it
		printf("\n\nPlease input your first value >> ");
		scanf("%lf", &value0);
		printf("\n\nPlease input your second value >> ");
		scanf("%lf", &value1);
		
		//Menu screen
		printf("\nWhat would you like to do with %.2f and %.2f?", value0, value1);
		printf("\n\t\t0\texit");
		printf("\n\t\t1\tadd\t(Value 1) + (Value 2))");
		printf("\n\t\t2\tsubtract\t(Value 1) - (Value 2)");
		printf("\n\t\t3\tmultiply\t(Value 1) x (Value 2)");
		printf("\n\t\t4\tdivide\t(Value 1) / (Value 2)");
		printf("\n\nChoice>> ");
		
		scanf("%d", &pick);
		if(pick > 0 & pick <= 4) {
			choice = pick;
			printf("%.2f", (*functionPtr[choice -1])(&value0, &value1));
		}
		//exit case: Changes value of choice to break the loop
		else if(pick == 0){
			printf("\nGoodbye! Have a nice day!\n\n\n\n\n\n");
			choice = 0;
		}	
		//This case if the value entered is outside the scope of the choices
		else
		{
			printf("I'm sorry, that choice was not valid. Please choose again:");
		}
	}

	return 0;
}

//Calculator Functions; perform the action, print the 
//header, and return the answer in response
double add(double * value0, double * value1) {
	double answer = 0;
	answer = *value0 + *value1;
	printf("\nResult>> %.2lf + %.2lf = ", *value0, *value1);
	return answer;
}
double subtract(double * value0, double * value1) {
	double answer = 0;
	answer = *value0 - *value1;
	printf("\nResult>> %.2lf - %.2lf = ", *value0, *value1);
	return answer;
}
double multiply(double * value0, double * value1) {
	double answer = 0;
	answer = *value0 * *value1;
	printf("\nResult>> %.2lf * %.2lf = ", *value0, *value1);
	return answer;
}
double divide(double * value0, double * value1) {
	double answer = 0;
	answer = *value0 / *value1;
	printf("\nResult>> %.2lf / %.2lf = ", *value0, *value1);
	return answer;
}

