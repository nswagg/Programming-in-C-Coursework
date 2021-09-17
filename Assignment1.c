/*
* Nick Waggoner
* Programming in C
* Due: 2-20-2020
*
*	This program collects an upper and lower bound on the celsius variable 
*	and converts each number from Celsius to Fahrenheit in Celsius increments
*	of 10 and prints them to the table. This program explicitly uses pass-
*	by-reference without any direct calls to the variables, even in the function
* 
* Tags: pointers
*/

#include <stdio.h>

void conversion(float*, float*);

void main()
{
	float counter = 0;
	float celsius = 0;
	float fahrenheit = 0;
	float swap = 0;
	float * counterPtr = NULL;
	float * celsiusPtr = NULL;
	float * fahrenPtr = NULL;
	float * swapPtr = NULL;
	counterPtr = &counter;
	celsiusPtr = &celsius;
	fahrenPtr = &fahrenheit;
	swapPtr = &swap;
	
	//Introduction
	printf("\nWelcome To Nick Waggoner's Celsius to Fahrenheit Converter\n");
	printf("\tThis program asks for lower and upper celsius values.\n");
	printf("\tThen prints to a table with the\n");
	printf("\tCelsius values in increments of 10 degrees with\n");
	printf("\tThe Fahrenheit conversions.");
	
	//Gets input and sets bounds to table
	printf("\n\nEnter the lower Celsius value > ");
	scanf(" %f", celsiusPtr);
	printf("Enter the upper Celsius value > ");
	scanf(" %f", counterPtr);
	
	//If the lower bound is smaller than the upper bound, swap them.
	if (*celsiusPtr > *counterPtr)
	{
		*swapPtr = *celsiusPtr;
		*celsiusPtr = *counterPtr;
		*counterPtr = *swapPtr;
	}
	
	printf("\n\n	Celsius		   Fahrenheit		");
	printf("\n__________________________________________");
	
	//iterates through every value in increments of 10 between bounds
	while(*celsiusPtr <= *counterPtr)
	{
		conversion(celsiusPtr, fahrenPtr);
		printf("\n\t%3.0f\t\t%10.2f", *celsiusPtr, *fahrenPtr);
		*celsiusPtr += 10;
	}
	
}//main

//Converts a celsius value to fahrenheit using pointers
void conversion(float *celsiusPtr, float *fahrenPtr)
{
	float cel;
	cel = *celsiusPtr;
	
	cel = (cel * 9 / 5) + 32;
	*fahrenPtr = cel;
}
