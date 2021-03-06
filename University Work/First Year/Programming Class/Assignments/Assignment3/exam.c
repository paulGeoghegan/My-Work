/*
	Description
This program allows the user to pick from various options listed below in order to check a code securely
Options:
1. This option allows a user to select between 2 options:
	1. The user can manually enter a 4 didget code,
	2. The user will have a 4 didget code generated for them
2. This option uses an incryption algorithm to let the user incrypt their code, 
where the first and third elements and the second and fourth elements are swapped,
Then 1 is added to each number and it is checked to see if it is equil to 10,
if so then it is changed to 0.
3. This option allows the user to compair their now incrypted code to the pre-defined correct code which while not incrypted is 1234 and while incrypted is 4523.
If the users code is correct then 1 is added to the correct_code variable stored in the attempts variable of the code_counter structure
else 1 is added to the wrong_code variable in the same structure
4. This option uses the same incryption algorithm but in reverse to decrypt the code entered by the user
5. This option allows the user to see how many correct and wrong attempts they have made
6. This option allows the user to exit the program by pressing 1 or resuming the program if they press 2
Note:
The errorCheck function is used to get and validate any numerical input from the user
The clear function is used to clear the screen after a function has completed running where at the end of the function the user presses enter to clear the screen
	Author
Paul Geoghegan
	Date
Started 04/04/20
Finished 06/04/20
Editted 14/05/20
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

//function signature
void enterNumbers(short[], bool*, bool*, bool*, bool*);
void incryptNumbers(short[], bool*, bool*, bool*);
void compairNumbers(short[], struct code_counter *attempts, bool*, bool*);
void decryptNumbers(short[], bool*, bool*);
void entryAttempts(struct code_counter *attempts);
void end();

//utility functions
short errorCheck(char[], short*, short*);
void clear();

void main()
{

	short min = 1;
	short max = 6;
	unsigned short userCode[LENGTH];
	char str[MINSTR];
	bool op1, op2, op3, op4;
	struct code_counter attempts;
	srand(time(0));

	//sets values in attempts to 0
	attempts.correct_code = 0;
	attempts.wrong_code = 0;

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

		//this switch case controlls which option the user wants to pick
		switch(errorCheck(str, &min, &max))
		{

			//this case will allow the user to enter or generate a code
			case 1:
			{

				//goes to the enter numbers function to allow the user to fill out the userCode array
				enterNumbers(userCode, &op1, &op2, &op3, &op4);

				//this breaks out of the case
				break;

			} //end case 1
			// This allows the user to incrypt there code
			case 2:
			{

				//this goes to the incryptNumbers function
				incryptNumbers(userCode, &op2, &op3, &op4);

				//This breaks out of the case
				break;

			} //end case 2
			// This allows the user to compair their code to the correct one
			case 3:
			{

				//goes to the compairNumbers function
				compairNumbers(userCode, &attempts, &op1, &op3);

				//This breaks out of the case
				break;

			} //end case 3
			// This allows the user to decrypt their code
			case 4:
			{

				//goes to the decryptNumbers function
				decryptNumbers(userCode, &op2, &op4);

				//This breaks out of the case
				break;

			} //end case 4
			//if the user wants to see the number of correct and incorrect attempts
			case 5:
			{

				//goes to the entryAttempts function
				entryAttempts(&attempts);

				//This breaks out of the case
				break;

			} //end case 5
			// This allows the user to exit the program
			case 6:
			{

				//goes to the end function to allow the user to exit the program
				end();

				//This breaks out of the case
				break;

			} //end case 6
			//if something goes wrong
			default:
			{

				//This lets the user know that there was an issue
				printf("Sorry something has gone wrong please try again\n");

			}//end default case

		} //end option switch case

		//goes to the clear function to clear text after each case has been complete
		clear();

	} //end do while
	while(1);

} //end main


//this function allows the user to enter a code in to the userCode array from the main function
void enterNumbers(short userCode[], bool *op1, bool *op2, bool *op3, bool *op4)
{

	short i = 0;
	short min = 1;
	short max = 2;
	char str[MINSTR];

	//Asks the user what they want to do
	printf("What do you want to do?\n1. Manually enter a code\n2. Randomly generate a code\n");

	//Gets an imput from the user and checks what they want to do
	if(errorCheck(str, &min, &max) == 1)
	{

		//asks the user to enter a code
		printf("Please enter a 4 didget code\n");

		//this sets the values of min to 0 and max to nine to be used in the error check function
		min = 0;
		max = 9;

		//loops through the userCode array and gets the user to fill it out
		for(register short i = 0;i < LENGTH;i++)
		{

			//lets the user know what didget they are entering
			printf("Didget %d/%d\n", i+1, LENGTH);

			//goes to the error check function and returns a value to the userCode array
			*(userCode+i) = errorCheck(str, &min, &max);

		} //end for

	} //end if
	else
	{

		//tells the user that a code is being generated
		printf("Generateing code...\n");

		//This loop will generate the four didget code
		for(register short i = 0;i < LENGTH;i++)
		{

			//generates a random number and stores it in the userCode array
			*(userCode+i) = rand() %10;

		} //end for

	} //end else

	printf("Your code is:\n");

	//prints the users code
	for(register short i = 0;i < LENGTH;i++)
	{

		//prints a didget from the userCode array
		printf("%d ", *(userCode+i));

	} //end for

	//prints a blank line to fix formatting
	printf("\n");

	//sets op1 to true so that the user cant keep compairing the same codes (see compairNumbers) and sets op2 to true so that the user can incrypt their number
	*op1 = *op2 = true;

	//sets all other options to false
	*op3 = *op4 = false;

} //end enterNumbers


//this function allows the user to incrypt their code
void incryptNumbers(short userCode[], bool *op2, bool *op3, bool *op4)
{

	short temp;

	//this checks if the user has already incrypted their code or if they have not entered a code
	if(*op2 == false && *op3 == true)
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

		//Lets the user know that their code is being incrypted
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
		*op3 = *op4 = true;

		//sets op2 to false so that the user cant try to incrypt the code again
		*op2 = false;

	} //end else

} //end incryptNumbers function


//this function allows the user to compair the incrypted code they have to the correct code
void compairNumbers(short userCode[], struct code_counter *attempts, bool *op1, bool *op3)
{

	const short access_code[] = {4, 5, 2, 3};
	register short i =0;

	//checks if the user has entered a code and incrypted it
	if(*op1 == true && *op3 == true)
	{

		printf("Checking code...\n");

		//checks to see if the users incrypted code matches the correct code
		do
		{

			//compairs two numbers 1 from userCode and the other from access_code
			if(*(userCode+i) == *(access_code+i))
			{

				//increases i by 1
				i++;

			} //end if

		} //end do while
		while(i < LENGTH && *(userCode+i) == *(access_code+i));

		//checks if i == 4 since if it is the users code was correct
		if(i == 4)
		{

			//tells the user that their code was correct
			printf("Correct Code entered\n");

			//increases the correct attempts by 1
			attempts->correct_code++;

		} //end if
		else
		{

			//lets the user know their code was wrong
			printf("Wrong Code entered\n");

			//increases the incorrect attempts by 1
			attempts->wrong_code++;

		} //end else

		//sets op1 and op3 to false so that the user must enter a new code befor compairing again
		*op1 = false;
		*op3 = false;

	} //end if
	else if(*op1 == false && *op3 == true)
	{

		//lets the user know they must enter a new code befor compairing again
		printf("Please enter a new code as this one has already been checked\n");

	} //end else if
	else
	{

		//asks the user to complete options 1 and 2 befor this one
		printf("Please enter a code and incrypt it befor selecting this option\n");

	} //end else

} //end compair numbers


//this function will allow the user to decrypt an already incrypted code
void decryptNumbers(short userCode[], bool *op2, bool *op4)
{

	short temp;

	//checks if the user has entered a code and incrypted it
	if(*op4 == false)
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

		//sets op2 to true so that the user can incrypt the code
		*op2 = true;

		//sets op4 to false so the user cant decrypt a code twice
		*op4 = false;

	} //end else

} //end decryptNumbers


//this function will display the correct and incorrect attempts made by the user
void entryAttempts(struct code_counter *attempts)
{

	printf("Entry attempts...\n");

	//displays the correct attempts
	printf("The amount of correct attempts made was %d\n", attempts->correct_code);

	//displays the incorrect attempts
	printf("The amount of wrong attempts made was %d\n", attempts->wrong_code);

} //end entryAttempts


//this function allows the user to end the program
void end()
{

	short min = 1;
	short max = 2;
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


/*
Note: these are extra utility functions which arent in the general requirements of the assignment but have been added for a better user experience
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
			scanf("%s", str);
			fflush(stdin);

			//checks to see if the input is valid
			//the last statement is used as if a non numeric char is converted to an int it will return 0 so this last statement checks for the user entering a 0 as otherwise this would not work as intended
			if((atoi(str) < *min || atoi(str) > *max || atoi(str) == 0) && strcmp(str, "0") != 0)
			{

				//Lets the user know that their imput was invalid
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

				//lets the user know that their imput was not valid
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

	//delays the program to fix an accessibility issue with clearing the screen in a terminal as otherwise the following print statements will not be read by screen readers
	Sleep(1000);

} //end clear function
