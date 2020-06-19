
//Header files
#include <stdio.h>
#include <string.h>
#include "structs.h"

void play(char dirName[])
{

	char str[11];
	long min, max;

	//This is the main loop for controlling the game
	do
	{

		//Lets the user know where they are
		printf("%s\n", map[character.y][character.x].name);
		printf("%d\n", map[character.y][character.x].id);
		printf("X %d, Y %d\n", character.x, character.y);

		//Gets an imput from the user
		gets(str);

		//Switch to run through all the options
		switch(str[0])
		{

			//moves upwards in the y direction
			case 'w':
			{

				//Makes sure movement wont let user move outside of the map
				if((character.y + 1) < 101)
				{

					//increases y by one
					character.y++;

				} //End if

				//Breaks out of switch
				break;

			} //end w case
			//Moves downwards in the y direction
			case 's':
			{

				//Makes sure movement wont let user move outside of the map
				if((character.y - 1) > -1)
				{

					//decreases y by one
					character.y--;

				} //End if

				//Breaks out of switch
				break;

			} //End s case
			//Moves to the right across the map
			case 'd':
			{

				//Makes sure movement wont let user move outside of the map
				if((character.x + 1) < 101)
				{

					//Increases x by one
					character.x++;

				} //End if

				//Breaks out of switch
				break;

			} //End d case
			//Moves to the left across the map
			case 'a':
			{

				//Makes sure movement wont let user move outside of the map
				if((character.x - 1) > -1)
				{

					//decreases x by one
					character.x--;

				} //End if

				//Breaks out of switch
				break;

			} //End a case
			default:
			{

				//Checks if the user wants to exit the game
				if(strcmp(str, "exit") == 0)
				{

					return;

				}//End exit case
				else if(strcmp(str, "ADMIN") == 0)
				{

					//Tells the user that they have entered the admin menu
					printf("Admin menu:\n");
					printf("1. teleport\n");

					//Sets values for min and max
					min = 1;
					max = 1;
					//Uses a switch for admin commands
					switch(errorCheck(&min, &max))
					{

						//Allows the user to teleport
						case 1:
						{

							//Sets values for min and max
							min = 0;
							max = mapSize-1;

							//Asks the user where they want to go for x
							printf("Enter X\n");
							character.x = errorCheck(&min, &max);

							//Asks the user where they want to go for y
							printf("Enter Y\n");
							character.y = errorCheck(&min, &max);

							//Breaks out of switch
							break;

						} //End teleport case

					} //End admin switch

				} //End else if

			} //End default case

		} //End switch

	} //End do while
	while(1);

} //End play
