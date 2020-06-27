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
#include <dirent.h>
#include <string.h>
#include "structs.h"
#include <gtk.h>

//function signatures
void save(char);

//Main function for the welcome menu
int main()
{

	short option;
	long min, max;
char dirName[11];

	//This is the menu loop for the game
	do
	{

		printf("Main menu\n");
		printf("Please select 1 of the following options by entering the corosponding number\n");
		printf("1. Create New Game\n");
		printf("2. Load An Existing Game\n");
		printf("0. End The Program\n");

		//sets values for min and max
		min = 0;
		max = 2;

		switch(errorCheck(&min, &max))
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

