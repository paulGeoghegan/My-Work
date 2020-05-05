/*
	Description
This program uses Euclids Algorithm to find the greatest common denominator (GCD) of 2 numbers and also finds x and y so that gcd = x(n1) - y(n2)
	Author
Paul Geoghegan
	Date
01/05/20
*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <limits.h>

//symbolic names
#define LENGTH 4
#define LENGTH2 7

//structures


//function signatures
long* part1(long*, long*);
long* swap(long*, long, long);
void part2(long *, long, long, long);

//utility functions
void end();
long errorCheck(char[], long*, long*);
void clear();

void main()
{

	long gcd, min, max;
	long *numbers;
	char str[2];

	//allocates memory for numbers which will be the main block of memory used throught the program
	numbers = calloc(LENGTH, sizeof(long));

	//This loop will continue untill the user chooses to end the program
	do
	{

		//sets values for min and max
		min = 1;
		max = 2;

		//asks the user what they want to do
		printf("Please choose from one of the following options:\n");
		printf("1. Run the algorithm\n");
		printf("2. Exit the program\n");

		//checks to see what the user wants to do
		switch(errorCheck(str, &min, &max))
		{

			case 1:
			{

				//this is temporary
				printf("Enter the 2 numbers\n");

				//sets values for min and max
				min = LONG_MIN  ;
				max = LONG_MAX  ;

				//stores numbers in memory block
				*(numbers+0) = errorCheck(str, &min, &max);
				*(numbers+2) = errorCheck(str, &min, &max);

				//goes to the part 1 function
				numbers = part1(numbers, &gcd);

				break;

			} //end case 1
			case 2:
			{

				//goes to the end function
				end();

			} //end case 2

		} // end switch case

		//clears screen
		clear();

	} // end do while
	while(1);

	free(numbers);

} //end main


//this function handles the first part of euclids algorithm to find the gcd
long* part1(long *numbers, long *gcd)
{

	int i, n1, n2, q, r;

	//sets value for i
	i = 1;

	//sets values for n1, n2, q and r
	n1 = (i*LENGTH)-4;
	q = (i*LENGTH)-3;
	n2 = (i*LENGTH)-2;
	r = (i*LENGTH)-1;

	//this loop will continue untill the gcd is found
	do
	{

		//performs calculation to find quotient
		*(numbers+q) = *(numbers+n1) / *(numbers+n2);

		//performs calculation to find the remainder
		*(numbers+r) = *(numbers+n1) % *(numbers+n2);

		//tells the user what line it is
		printf("Line %d\n", i);

		//prints the calculated line
		printf("%ld = %ld(%ld) + %ld", *(numbers+n1), *(numbers+q), *(numbers+n2), *(numbers+r));

		//checks to see if the calculation is complete
		if(*(numbers+r) != 0)
		{

			//adds 1 to i
			i++;

			//reallocates memory
			numbers = realloc(numbers, (sizeof(long)*(i*4)));


			//re-calculates n1 and then swaps values with n2
			n1 = (i*LENGTH)-4;
			*(numbers+n1) = *(numbers+n2);

			//re-calculates value for n2 and swaps value with r
			n2 = (i*LENGTH)-2;
			*(numbers+n2) = *(numbers+r);

			//calculates values for q and r
			q = (i*LENGTH)-3;
			r = (i*LENGTH)-1;

		} //end if

	} // end do while
	while(*(numbers+r) != 0);

	//sets value for gcd
	*gcd = *(numbers+n2);

	//displays GCD
	printf("The gcd of %ld and %ld is %ld", *(numbers+0), *(numbers+2), gcd);

	//goes to the swap function
	numbers = swap(numbers, i, *gcd);

	return numbers;
} // end part1


//this function swaps around the elements in the numbers array so that they will be ready to be used in part2 of euclids algorithm
long* swap(long*numbers, long j, long gcd)
{

	long n1, q, n2, r, temp;

	//this will loop through the numbers memory block
	for(long i =1;i < j;i++)
	{

		//sets values for n1, n2, q and r
		n1 = (i*LENGTH)-4;
		q = (i*LENGTH)-3;
		n2 = (i*LENGTH)-2;
		r = (i*LENGTH)-1;

		//swaps values
		temp = *(numbers+r);
		*(numbers+r) = *(numbers+n2);
		*(numbers+n2) = *(numbers+q) *-1;
		*(numbers+q) = *(numbers+n1);
		*(numbers+n1) = gcd;

	} //end for

} //end swap

//this is part 2 of euclids algorithm which will find x and y values so that d = x(n1) + y(n2)
void part2(long *temp, long gcd, long num1, long num2)
{

	long i, d, q1, q2, q3, n1, n2, n3;
	long *numbers;

	//allocates memory for numbers
	numbers = calloc(LENGTH2, sizeof(long));

	//assignes values for all other variables
	i = 1;
	d = i-(i*LENGTH2)-7;
	q1 = (i*LENGTH2)-6;
	n1 = (i*LENGTH)-5;
	q2 = (i*LENGTH2)-4;
	n2 = (i*LENGTH2)-3;
	q3 = (i*LENGTH2)-2;
	n3 = (i*LENGTH2)-1;

	//this loop will continue untill the final line of the solution has been solved
	do
	{

	} //end do while
	while(*(numbers+n1) != num1 && *(numbers+n2) != num2);

	//frees memory block
	free(numbers);

} //end part2

/*
NOTE: These following functions have been included purely for the sake of improveing usability and serve no function for euclids algorithm
*/

//this function allows the user to end the program
void end()
{

	long min = 1;
	long max = 2;
	char str[2];

	//asks the user if they want to end the program
	printf("Are you sure you want to end the program?\n1: yes\n2: no\n");

	//gets an input from the user and checks what they want to do
	if(errorCheck(str, &min, &max) == 1)
	{

		//tells the user that the program is stopping
		printf("Exiting program...");

		//exits the program
		exit(0);

		} //end if
		else
		{

			//lets the user know that the program is not exiting
			printf("Resuming program\n");

		} //end else

} //end end function


//this function error checks any input from the user
long errorCheck(char str[], long *min, long *max)
{

	long num;

	//checks to see if the min value required is < 1 as this requires slightly different logic
	if(*min < 1)
	{

		//this gets an input from the user and error checks it
		do
		{

			//gets the input from the user and then clears the input buffer
			scanf("%1s", str);
			fflush(stdin);

			//checks to see if the input is valid
			//the last statement is used as if a non numeric char is converted to an int it will return 0 so this last statement checks for the user entering a 0 as otherwise this would not work as intended
			if((atoi(str) < *min || atoi(str) > *max || atoi(str) == 0) && strcmp(str, "0") != 0)
			{

				printf("Invalid input please enter a value from %d to %d\n", *min, *max);

			} //end if

		} //end do while also see note above
		while((atoi(str) < *min || atoi(str) > *max || atoi(str) == 0) && strcmp(str, "0"));

	} //end if
	else
	{

		//this gets an input from the user and error checks it
		do
		{

			//gets the input from the user and then clears the input buffer
			scanf("%s", str);
			fflush(stdin);

			//checks to see if the input is valid
			if(atoi(str) < *min || atoi(str) > *max)
			{

				printf("Invalid input please enter a value from %d to %d\n", *min, *max);

			} //end if

		} //end do while
		while(atoi(str) < *min || atoi(str) > *max);

	} //end else

	// returns num
	return num = atoi(str);

} //end errorCheck


//this function will clear the screen at the end of each of the functions
void clear()
{

	//this tells the user to press the enter key to continue
	printf("Press enter to continue\n");

	//this takes an input from the user but doesnt store it anywhere
	getchar();

	//this clears the screen
	system("CLS");

	//delays the program to fix an accessibility issue with clearing the screen in a terminal
	Sleep(1000);

} //end clear function
