
//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

//function signature
void end();
long errorCheck(long*, long*);
void clear();

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

	//this takes an input from the user but doesnt store it anywhere and clears the buffer
	getchar();
	fflush(stdin);

	//this clears the screen
	system("CLS");

	//delays the program to fix an accessibility issue with clearing the screen in a terminal
	Sleep(1000);

} //end clear function
