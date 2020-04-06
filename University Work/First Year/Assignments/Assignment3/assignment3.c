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

//global variables
bool op2, op3, op4;

//symbolic names
#define LENGTH 4
#define MINSTR 2

//structures
struct code_counter
{
	int correct_code; 
	int wrong_code;
};

//function signature
void enterNumbers(short[]);
void incryptNumbers(short[]);
void compairNumbers(short[]);
void decryptNumbers(short[]);
void entryAttempts(struct code_counter attempts);
void end();

//utility functions
void errorCheck(char[], short*, short*);
void clear();

void main()
{

	short option;
	unsigned short userCode[LENGTH];
	char str[MINSTR];
	struct code_counter attempts;
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

		//this gets a value from the user and error checks it so that the user can choose an option
		do
		{

			//this gets an input from the user and empties the input buffer
			scanf("%1s", str);
			fflush(stdin);


			//this converts the character that the user entered in to a number corosponding with its ascii value
			option = atoi(str);

			//this checks if the value entered by the user is valid
			if(option < 1 || option > 6)
			{

				printf("Invalid input, Please enter a value between 1 and 6\n");

			} //end if

		} //end do while
		while(option < 1 || option > 6);
		while(option < 1 || option > 6);

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

				break;

			} //end case 3
			//if the user wants to decrypt their code
			case 4:
			{

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
	short option;
	char str[MINSTR];

	printf("What do you want to do?\n1. Manually enter a code\n2. Randomly generate a code\n");

	//this checks what option the user wants to choose
	do
	{

		//gets an input from the user
		scanf("%1s", str);
		fflush(stdin);

		//checks the users input
		if(atoi(str) < 1 || atoi(str) > 2)
		{

			printf("Invalid input please either enter 1 for a manual input or 2 for a randomly generated one\n");

		} //end if

	} //end do while
	while(atoi(str) < 1 || atoi(str) > 2);

	//this stores the users selected option in the option variable by useing atoi
	option = atoi(str);

	//this switch case allows the user to pick between a manual and random code
	switch(option)
	{

		case 1:
		{

			printf("Please enter a 4 didget code\n");

			//this gets an input from the user to fill out the userCode array
			do
			{

				printf("Didget %d/%d\n", i+1, LENGTH);

				//gets the users input and error checks it
				do
				{

					//gets an input from the user and then empties the input buffer
					scanf("%1s", str);
					fflush(stdin);

					//lets the user know if there input is invalid
					//note: the last statement to check if the first char in str is not equil to the char 0 is used as atoi returns 0 if the value could not be converted to an int hence all non numerical characters would not be caught by this statement
					if((atoi(str) < 1 || atoi(str) > 9) && *(str) != '0')
					{

						printf("Invalid input please enter a didget from 0 to 9\n");

					} //end if

				} //end do while also see note above
				while((atoi(str) < 1 || atoi(str) > 9) && *(str) != '0');

				//adds the didget to the userCode array
				*(userCode+i) = atoi(str);

				//adds 1 to i for indexing
				i++;

			} //end do while
			while(i < LENGTH);

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
		printf("It appears as if you have not entered a new code please enter one and tyy again\n");

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

	} //end else

} //end incryptNumbers function


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
void errorCheck(char str[], short *min, short *max)
{

	printf("Temp");

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
	Sleep(2);

} //end clear function
