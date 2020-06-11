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

//Symbolic names
#define mapSize 101

//function signatures
void save(short[][mapSize], char);
void tiles(short);

//utility functions
void end();
long errorCheck(long*, long*);
void clear();

int main()
{

	short option;
	long min, max;
	short map[mapSize][mapSize];

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
				save(map, 'c');
				break;

			} //end case 1
			//This case will load a save
			case 2:
			{

				//Goes to the save function in order to load an existing save
				save(map, 'l');
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
