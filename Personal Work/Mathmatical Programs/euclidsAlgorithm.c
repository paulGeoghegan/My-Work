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

//symbolic names
#define LENGTH 4

//structures


//function signatures
long* part1(long*, long*);

void main()
{

	long gcd, num1, num2;
	long *numbers;

	//allocates memory for numbers which will be the main block of memory used throught the program
	numbers = calloc(LENGTH, sizeof(long));

	//this is temporary
	printf("Enter the 2 numbers\n");

	//puts num1 and num2 in the numbers memory block
	scanf("%ld", &*(numbers+0));
	scanf("%ld", &*(numbers+2));

	//goes to the part 1 function
	numbers = part1(numbers, &gcd);

	//displays GCD
	printf("The gcd of %ld and %ld is %ld", *(numbers+0), *(numbers+2), gcd);

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

		//sets values for n1, n2, q and r
		n1 = (i*LENGTH)-4;
		q = (i*LENGTH)-3;
		n2 = (i*LENGTH)-2;
		r = (i*LENGTH)-1;

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


			//recalculates n1 and then swaps values with n2
			n1 = (i*LENGTH)-4;
			*(numbers+n1) = *(numbers+n2);

			//recalculates value for n2 and swaps value with r
			n2 = (i*LENGTH)-2;
			*(numbers+n2) = *(numbers+r);

		} //end if

	} // end do while
	while(*(numbers+r) != 0);

	//sets value for gcd
	*gcd = *(numbers+n2);

	return numbers;
} // end part1
