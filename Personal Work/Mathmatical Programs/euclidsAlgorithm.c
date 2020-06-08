/*
	Description
This program uses Euclids Algorithm to find the greatest common denominator (GCD) of 2 numbers and also finds x and y so that gcd = x(n1) - y(n2)
	Author
Paul Geoghegan
	Date
Started 01/05/20
Finished 07/06/20
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

//function signatures
void part1(long*, long*);
void swap(long*, long, long);
void part2(long *, long, long);

//utility functions
void end();
long errorCheck(long*, long*);
void clear();

int main()
{

	long gcd, min, max;
	long *numbers;
	short cont = 1;

	//allocates memory for numbers which will be the main block of memory used throught the program
	numbers = calloc(LENGTH, sizeof(long));

	//This loop will continue until the user chooses to end the program
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
		switch(errorCheck(&min, &max))
		{

			case 1:
			{

				printf("Enter the 2 numbers: X and Y in order to find the GCD\n");

				//sets values for min and max
				min = LONG_MIN;
				max = LONG_MAX;

				//stores numbers in memory block
				*(numbers+0) = errorCheck(&min, &max);
				*(numbers+2) = errorCheck(&min, &max);

				//checks if the second number is larger than the first and if so they get swapped
				if(*(numbers+2) > *(numbers+0))
				{

					//swaps numbers around
					*(numbers+1) =*(numbers+0);
					*(numbers+0) = *(numbers+2);
					*(numbers+2) = *(numbers+1);

				} //end if

				//goes to the part 1 function
				part1(numbers, &gcd);
				break;

			} //end case 1
			case 2:
			{

				//goes to the end function
				end();

				//Infinite loops aren't great, also you're a nerd
				cont = 0;

				break;

			} //end case 2

		} // end switch case

		//clears screen
		clear();

	} // end do while
	while(cont == 1);

} //end main


//this function handles the first part of euclid's algorithm to find the gcd
void part1(long *numbers, long *gcd)
{

	int i, n1, n2, q, r;
	char loop;

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
			numbers = realloc(numbers, (sizeof(long)*(i*LENGTH)));

			//re-calculates n1 and then swaps values with n2
			n1 = (i*LENGTH)-4;
			*(numbers+n1) = *(numbers+n2);

			//re-calculates value for n2 and swaps value with r
			n2 = (i*LENGTH)-2;
			*(numbers+n2) = *(numbers+r);

			//calculates values for q and r
			q = (i*LENGTH)-3;
			r = (i*LENGTH)-1;

			//sets value of continue to y
			loop = 'y';

		} //end if
		else
		{

			//sets value of continue to n
			loop = 'n';

		} //end else

	} // end do while
	while(loop == 'y');

	//sets value for gcd
	*gcd = *(numbers+n2);

	//displays GCD
	printf("The gcd of %ld and %ld is %ld\n", *(numbers+0), *(numbers+2), *gcd);

	//if numbers has more than 1 row then the last row isnt needed for part 2 so this will check and remove it
	if(i > 1)
	{

		//reallocates the numbers memory block and changes the value of i
		i--;
		numbers = realloc(numbers, (sizeof(long) * LENGTH));

	} //end if

	//goes to the swap function
	swap(numbers, i, *gcd);

} // end part1


//this function swaps around the elements in the numbers array so that they will be ready to be used in part2 of euclids algorithm
void swap(long*numbers, long j, long gcd)
{

	long n1, q, n2, r;
	long register i;

	//this will loop through the numbers memory block
	for(i = 1;i <= j;i++)
	{

		//sets values for n1, n2, q and r
		n1 = (i*LENGTH)-4;
		q = (i*LENGTH)-3;
		n2 = (i*LENGTH)-2;
		r = (i*LENGTH)-1;

		//swaps values
		*(numbers+r) = *(numbers+n2);
		*(numbers+n2) = *(numbers+q) *-1;
		*(numbers+q) = *(numbers+n1);
		*(numbers+n1) = gcd;

	} //end for

	//goes to the part 2 function
	part2(numbers, j, gcd);

} //end swap


//this is part 2 of euclids algorithm which will find x and y values so that d = x(n1) + y(n2)
void part2(long *temp, long j, long gcd)
{

	long d, q1, q2, q3, n1, n2, n3, tempQ, tempN1, tempN2;
	long numbers[LENGTH2] = {0};

	//assignes values for all other variables
	d = 0;
	q1 = 1;
	n1 = 2;
	q2 = 3;
	n2 = 4;
	q3 = 5;
	n3 = 6;

	//gives values to index variables for the temp array
	tempN1 = (j*LENGTH)-3;
	tempQ = (j*LENGTH)-2;
	tempN2 = (j*LENGTH)-1;

	//puts initial values in the numbers array
	numbers[d] = gcd;
	numbers[q1] = 1;
	numbers[n1] = *(temp+tempN1);
	numbers[q2] = *(temp+tempQ);
	numbers[n2] = *(temp+tempN2);

	//this loop will continue untill the final line of the solution has been solved
	for(j = j-1;j > 0;j--)
	{

		//re-calculates values to index variables for the temp array
		tempN1 = (j*LENGTH)-3;
		tempQ = (j*LENGTH)-2;
		tempN2 = (j*LENGTH)-1;

		//checks to see where to substitute the numbers
		if(numbers[n1] < numbers[n2])
		{

			//moves n2 and q2 in to n3 and q3 respectivley
			numbers[n3] = numbers[n2];
			numbers[q3] = numbers[q2];

			//puts numbers from previous line that were after the = after they had been swapped in to n1, q2 and n2
			numbers[n1] = *(temp+tempN1);
			numbers[q2] = *(temp+tempQ);
			numbers[n2] = *(temp+tempN2);

			//multiplies out brackit as the equation should currently look like d = q1(n1 + q2(n2)) -q3(n3)
			numbers[q2] = numbers[q1] * numbers[q2];

			//checks if any of the n numbers are the same
			if((unsigned) numbers[n1] == (unsigned) numbers[n3])
			{

				//symplifies equation
				numbers[q1] = numbers[q1] * numbers[q3];

			} // end if
			else if((unsigned) numbers[n2] == (unsigned) numbers[n3])
			{

				//simplifies equation
				numbers[q2] = numbers[q2] * numbers[q3];

			} // end else if
			else
			{

				//lets the user know that something went wrong
				printf("Sorry something has gone wrong please try again\nError code 1");

			} //end else

		} //end if
		else if(numbers[n2] < numbers[n1])
		{

			//puts numbers from previous line that were after the = after they had been swapped in to n2, q3 and n3
			numbers[n2] = *(temp+tempN1);
			numbers[q3] = *(temp+tempQ);
			numbers[n3] = *(temp+tempN2);

			//multiplies out brackit as the equation should currently look like d = q1(n1) - q2(n2 +q3(n3))
			numbers[q3] = numbers[q2] * numbers[q3];

			//checks if any of the n numbers are the same
			if((unsigned) numbers[n2] == (unsigned) numbers[n1])
			{

				//simplifies equation
				numbers[q1] = numbers[q1] * numbers[q2];

				//moves q3 and n3 to q2 and n2
				numbers[q2] = numbers[q3];
				numbers[n2] = numbers[n3];

			} // end if
			else if((unsigned) numbers[n3] == (unsigned) numbers[n1])
			{

				//simplifies equation
				numbers[q1] = numbers[q1] * numbers[q3];

			} // end else if
			else
			{

				//Lets the user know that something went wrong
				printf("Sorry something has gone wrong please try again\nError code 2\n");

			} //end else

		} //end else if
		else
		    {

				//Lets the user know that something has gone wrong
				printf("Sorry something has gone wrong\nError code 3");

			} //end else

	} //end for

    //this prints the final line of part2 of euclid's algorithm
	printf("The answer to part 2 is\n");
	printf("%ld = %ld(%ld) %ld(%ld)\n", numbers[d], numbers[q1], numbers[n1], numbers[q2], numbers[n2]);
	printf("x = %ld\n", numbers[q1]);
	printf("y = %ld\n", numbers[q2]);

	//this frees the memory block for numbers
	free(temp);

} //end part2


/*
NOTE: These following functions have been included purely for the sake of improving usability and serve no function for euclid's algorithm
*/


//this function allows the user to end the program
void end()
{

	long min = 1;
	long max = 2;

	//asks the user if they want to end the program
	printf("Are you sure you want to end the program?\n1: yes\n2: no\n");

	//gets an input from the user and checks what they want to do
	if(errorCheck(&min, &max) == 1)
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
long errorCheck(long *min, long *max)
{

	char *ptr;
	char str[11];

	//checks to see if the min value required is < 1 as this requires slightly different logic
	if(*min < 1)
	{

		//this gets an input from the user and error checks it
		do
		{

			//gets the input from the user and then clears the input buffer
			scanf("%s", str);
			fflush(stdin);

			//checks to see if the input is valid
			//the last statement is used as if a non numeric char is converted to an int it will return 0 so this last statement checks for the user entering a 0 as otherwise this would not work as intended
			if((strtol(str, &ptr, 10) < *min || strtol(str, &ptr, 10) > *max || strtol(str, &ptr, 10) == 0) && strcmp(str, "0") != 0)
			{

				printf("Invalid input please enter a value from %ld to %ld\n", *min, *max);

			} //end if

		} //end do while also see note above
		while((strtol(str, &ptr, 10) < *min || strtol(str, &ptr, 10) > *max || strtol(str, &ptr, 10) == 0) && strcmp(str, "0"));

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
			if(strtol(str, &ptr, 10) < *min || strtol(str, &ptr, 10) > *max)
			{

				printf("Invalid input please enter a value from %ld to %ld\n", *min, *max);

			} //end if

		} //end do while
		while(strtol(str, &ptr, 10) < *min || strtol(str, &ptr, 10) > *max);

	} //end else

	// returns num
	return strtol(str, &ptr, 10);

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
