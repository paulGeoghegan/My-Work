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


//structures


//function signatures
long* part1(long*, long*);

void main()
{

	long gcd, num1, num2;
	long *numbers;

	//allocates memory for numbers which will be the main block of memory used throught the program
	numbers = calloc(4, sizeof(long));

	//this is temporary
	printf("Enter the 2 numbers\n");

	//puts num1 and num2 in the numbers memory block
	scanf("%ld", &*(numbers+0));
	scanf("%ld", &*(numbers+2));

	//goes to the part 1 function
	numbers = part1(numbers, &gcd);

	free(numbers);

} //end main


//this function handles the first part of euclids algorithm to find the gcd
long* part1(long *numbers, long *gcd)
{

	int i = 1;

	//this loop will continue untill the gcd is found
	do
	{

		//tells the user what line it is
		printf("Line %d\n", i);

		//finds how many times num2 devides in to num1
		*(numbers+((i*4)-3)) = *(numbers+((i*4)-4)) / *(numbers+((i*4)-2));

		//gets remainder of the above devision
		*(numbers+((i*4)-1)) = *(numbers+((i*4)-4)) % *(numbers+((i*4)-2));

		//prints out line of maths
		printf("%ld = %ld(%ld) + %ld\n", *(numbers+((i*4)-4)), *(numbers+((i*4)-3)), *(numbers+((i*4)-2)), *(numbers+((i*4)-1)));

		//reallocates memory if the algorithm hasnt finished
		if(*(numbers+((i*4)-1)) != 0)
		{

			//adds 1 to i
			i++;

			//reallocates memory
			numbers = realloc(numbers, (sizeof(long) * (i*4)));

		} //end if

	} // end do while
	while(*(numbers+((i*4)-1)) != 0);

	return numbers;
} // end part1
