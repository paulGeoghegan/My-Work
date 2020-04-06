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

void main()
{

	short option;
	unsigned short userCode[LENGTH];
	char str[MINSTR];
	struct code_counter attempts;

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

		if(option == 1)
		{

			//goes to the enterNumbers function
			enterNumbers(userCode);

	}	 //end if for option 1
		else if(option == 6)
	{	

			end();

		} //end else if for option 6

	} //end do while
	while(1);

} //end main


//this function allows the user to enter a code in to the userCode array from the main function
void enterNumbers(short userCode[])
{

	short i = 0;
	char str[MINSTR];

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

} //end enterNumbers


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
