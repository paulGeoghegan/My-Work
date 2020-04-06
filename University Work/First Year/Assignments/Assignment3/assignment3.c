/*
	Description

	Author
Paul Geoghegan
	Date
Started 04/04/20
Finished x/04/20
*/

//header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <windows.h>
#include <string.h>

//symbolic names
#define LENGTH 4
#define MINSTR 2

//structures
struct code_counter
{
	int correct_code; 
	int wrong_code;
};

//global variables
bool op2, op3, op4;
struct code_counter attempts;

//function signature
void enterNumbers(short[]);
void incryptNumbers(short[]);
void compairNumbers(short[]);
void decryptNumbers(short[]);
void entryAttempts();
void end();

//utility functions
short errorCheck(char[], short*, short*);
void clear();

void main()
{

	short option;
	short min = 1;
	short max = 6;
	unsigned short userCode[LENGTH];
	char str[MINSTR];
	srand(time(0));

	//this is the main loop for looping continiously through the program untill the user chooses to end the program
	do
	{

		//this prints the main menu for the program
		printf("\nPlease choose from one of the following options\n");
		printf("1. Enter a code\n");
		printf("2. Incrypt a code\n");
		printf("3. Check code\n");
		printf("4. Decrypt a code\n");
		printf("5. Check entry attempts\n");
		printf("6. Exit the program\n\n");

		//this sets option equil to the value returned by the errorCheck function
		option = errorCheck(str, &min, &max);

		switch(option)
		{

			case 1:
			{

				//goes to the enter numbers function to allow the user to fill out the userCode array
				enterNumbers(userCode);
				break;

			} //end case 1
			//if the user wants to incrypt there code
			case 2:
			{

				//this goes to the incryptNumbers function
				incryptNumbers(userCode);
				break;

			} //end case 2
			//if the user wants to compair their code to the correct one
			case 3:
			{

				//goes to the compairNumbers function
				compairNumbers(userCode);
				break;

			} //end case 3
			//if the user wants to decrypt their code
			case 4:
			{

				//goes to the decryptNumbers function
				decryptNumbers(userCode);
				break;

			} //end case 4
			//if the user wants to see the number of correct and incorrect attempts
			case 5:
			{

				break;

			} //end case 5
			//if the user wants to exit the program
			case 6:
			{

				//goes to the end function to allow the user to exit the program
				end();
				break;

			} //end case 6
			//if something goes wrong
			default:
			{

				printf("Sorry something has gone wrong please try again\n");

			}//end default case

		} //end option switch case

		//goes to the clear function
		clear();

	} //end do while
	while(1);

} //end main


//this function allows the user to enter a code in to the userCode array from the main function
void enterNumbers(short userCode[])
{

	short i = 0;
	short min = 1;
	short max = 2;
	short option;
	char str[MINSTR];

	printf("What do you want to do?\n1. Manually enter a code\n2. Randomly generate a code\n");

	//goes to the errorCheck function and return a value to option
	option = errorCheck(str, &min, &max);

	//this switch case allows the user to pick between a manual and random code
	switch(option)
	{

		case 1:
		{

			printf("Please enter a 4 didget code\n");

			//this sets the values of min to 0 and max to nine to be used in the error check function
			min = 0;
			max = 9;

			//loops through the userCode array ajnd gets the user to fill it out
			for(register short i = 0;i < LENGTH;i++)
			{

				//lets the user know what didget they are entering
				printf("Didget %d/%d\n", i+1, LENGTH);

				//goes to the error check function and returns a value to the userCode array
				*(userCode+i) = errorCheck(str, &min, &max);

			} //end for

			//breaks out of the switch case
			break;

		} //end case 1
		//this case randomly generates the code for the user
		case 2:
		{

			printf("Generateing code...\n");

			for(register short i = 0;i < LENGTH;i++)
			{

				//generates a random number and stores it in the userCode array
				*(userCode+i) = rand() %10;

			} //end for

			//breaks out of the switch case
			break;

		} //end case 2
		//if something goes wrong
		default:
		{

			printf("Something has gone wrong please try again\n");

		} //end default case

	} //end option switch case

	printf("Your code is:\n");

	//prints the users code
	for(register short i = 0;i < LENGTH;i++)
	{

		//prints a didget from the userCode array
		printf("%d ", *(userCode+i));

	} //end for

	//prints a blank line to fix formatting
	printf("\n");

	//this changes op2 to true so that the user may incrypt their code
	op2 = true;

} //end enterNumbers


//this function allows the user to incrypt their code
void incryptNumbers(short userCode[])
{

	short temp;

	//this checks if the user has already incrypted their code or if they have not entered a code
	if(op2 == false && op3 == true)
	{

		//tells the user they cant incrypt a code more than once
		printf("This code has already been incrypted\n");

	} //end if
	else if(op2 == false)
	{

		//tells the user that they need to enter a code befor they can incrypt it
		printf("It appears as if you have not entered a new code please enter one and try again\n");

	} //end else if
	else
	{

		printf("Incrypting code\n");

	//this incrypts the users code
		for(register short i = 0;i < LENGTH/2;i++)
		{

			//stores one didget in temp so it isnt over written
			temp = *(userCode+i);

			//swaps didgets
			*(userCode+i) = *(userCode+(i+(LENGTH/2)));
			*(userCode+(i+(LENGTH/2))) = temp;

		} //end for

		//adds one to each didget and checks the bounding
		for(register short i = 0;i < LENGTH;i++)
		{

			//adds one to each of the re-aranged didgets
			*(userCode+i) = *(userCode+i) + 1;

			//checks to see if this number is still within the bounds of the code
			if(*(userCode+i) == 10)
			{

				//replaces the 10 with a 0
				*(userCode+i) = 0;

			} //end if

		} //end for

		//lets the user know that there code has been incrypted
		printf("Code Incrypted\n");

		//sets op3 and op4 to true so that the user can check the incrypted code and or decrypt the code
		op3 = op4 = true;

		//sets op2 to false so that the user cant try to incrypt the code again
		op2 = false;

	} //end else

} //end incryptNumbers function


//this function allows the user to compair the incrypted code they have to the correct code
void compairNumbers(short userCode[])
{

	const short correctCode[] = {4, 5, 2, 3};
	register short i =0;

	//checks if the user has entered a code and incrypted it
	if(op3 == true)
	{

		printf("Checking code...\n");

		//checks to see if the users incrypted code matches the correct code
		do
		{

			//compairs two numbers 1 from userCode and the other from correctCode
			if(*(userCode+i) == *(correctCode+i))
			{

				//increases i by 1
				i++;

			} //end if

		} //end do while
		while(i < LENGTH && *(userCode+i) == *(correctCode+i));

		//checks if i == 4 since if it is the users code was correct
		if(i == 4)
		{

			//tells the user that their code was correct
			printf("The code you entered was correct\n");

			//increases the correct attempts by 1
			attempts.correct_code++;

		} //end if
		else
		{

			//lets the user know their code was wrong
			printf("That code was incorrect please try again\n");

			//increases the incorrect attempts by 1
			attempts.wrong_code++;

		} //end else

		//sets op2 and 3 to false
		op3 = false;

	} //end if
	else
	{

		//asks the user to complete options 1 and 2 befor this one
		printf("Please enter a code and incrypt it befor selecting this option\n");

	} //end else

} //end compair numbers


//this function will allow the user to decrypt an already incrypted code
void decryptNumbers(short userCode[])
{

	short temp;

	//checks if the user has entered a code and incrypted it
	if(op4 == false)
	{

		//tells the user to enter a code and incrypt it befor selecting this option
		printf("You must have an incrypted code to be able to incrypt it\n");

	} //end if
	else
	{

		//lets the user know that their code is being decrypted
		printf("Decrypting code...\n");

		//subtracts 1 from each of the numbers in the array and checks the bounds of the numbers
		for(register short i = 0;i < LENGTH;i++)
		{

			//subtracts one from each number in the code
			*(userCode+i) = *(userCode+i) - 1;

			//checks if the number is now equil to -1
			if(*(userCode+i) == -1)
			{

				//changes this number to 9
				*(userCode+i) = 9;

			} //end if

		} //end for

		//swaps the numbers
		for(register short i = 0;i < LENGTH/2;i++)
		{

			//stores value in temp to stop it being over written
			temp = *(userCode+i);

			//swaps numbers
			*(userCode+i) = *(userCode+(i+(LENGTH/2)));
			*(userCode+(i+(LENGTH/2))) = temp;

		} //end for

		//tells the user that the code has been decrypted
		printf("Code decrypted\n");

	} //end else

} //end decryptNumbers

//this function allows the user to end the program
void end()
{

	char choose;

	//asks the user if they want to end the program
	printf("Are you sure you want to end the program?\nY: yes\nN: no\n");

	//gets an input from the user and error checks it
	do
	{

		//gets an input from the user
		scanf("%1s", &choose);

		//checks to see if the user entered a valid input
		if(choose != 'n' && choose != 'N' && choose != 'y' && choose != 'Y')
		{

			printf("Invalid input, Please either enter y to exit the program or n to resume the program\n");

		} //end if

	} //end do while
	while(choose != 'n' && choose != 'N' && choose != 'y' && choose != 'Y');

	//checks if the user wants to exit the program
	switch(choose)
	{

		//this case exicutes if the user wishes to exit the program
		case 'y':
		case 'Y':
		{

			printf("Exiting program...\n");
			exit(0);
			break;

		} //end yes case
		//this case exicutes if the user wishes to continue the program
		case 'n':
		case 'N':
		{

			printf("Resumeing program\n");
			break;

		} //end no case
		//this case exicutes if something goes wrong
		default:
		{

			printf("Something has gone wrong please try again\n");

		} //end default case

	} //end switch case

} //end end function


/*
Note: these are extra utility functions which arent in the general requirements of the assignment
*/


//this function error checks any input from the user
short errorCheck(char str[], short *min, short *max)
{

	short num;

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
	Sleep(5);

} //end clear function
