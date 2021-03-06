/*
	Description
This will be a text based game written in C
More information will be added as the program is developed
	Author
Paul Geoghegan
	Date
08/06/20
*/

//Header files
#include <stdio.h>
#include <string.h>
#include "structs.h"

//function signatures
void save(char);

//Main function for the welcome menu
int main()
{

	short option;
	long min, max;


	//This is the menu loop for the game
	do
	{

		printf("Main menu\n");
		printf("Please select 1 of the following options by entering the corresponding number\n");
		printf("1. Create New Game\n");
		printf("2. Load An Existing Game\n");
		printf("0. End The Program\n");

		//sets values for min and max
		min = 0;
		max = 2;

		//This switch will check what option the user wants to pick
		switch(errorCheck(min, max))
		{

			//this case will create a new save
			case 1:
			{

				//Goes to the save function to create a new save
				save('c');
				break;

			} //end case 1
			//This case will load a save
			case 2:
			{

				//Goes to the save function in order to load an existing save
				save('l');
				break;

			} //end case 2
			case 0:
			{

				//Goes to the end function
				end();
				break;

			} //end case 0

		} //end switch

		//Clears the screen
		clear();

	} //end do while
	while(1);

	return 0;
} //end main

