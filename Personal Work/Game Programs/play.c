
//Header files
#include <stdio.h>
#include <string.h>

//Symbolic names
#define mapSize 101

//Structures
struct playerCharacter
{
	char name[21];
	short level;
	int xp;
	char *statNames[6];
	short stats[6];
	short x;
	short y;
}; //End playerCharacter

struct tile
{
	char name[21];
	short id;
	char description[100];
}; //End tile struct

//Function signatures
long errorCheck(long*, long*);

void play(struct playerCharacter *character, struct tile map[][mapSize], char dirName[])
{

	char str[11];
	long min, max;

	//This is the main loop for controlling the game
	do
	{

		//Lets the user know where they are
		printf("%s\n", map[character->y][character->x].name);
		printf("X %d, Y %d\n", character->x, character->y);

		//Gets an imput from the user
		gets(str);

		//Switch to run through all the options
		switch(str[0])
		{

			//moves upwards in the y direction
			case 'w':
			{

				//Makes sure movement wont let user move outside of the map
				if((character->y + 1) < 101)
				{

					//increases y by one
					character->y++;

				} //End if

				//Breaks out of switch
				break;

			} //end w case
			//Moves downwards in the y direction
			case 's':
			{

				//Makes sure movement wont let user move outside of the map
				if((character->y - 1) > -1)
				{

					//decreases y by one
					character->y--;

				} //End if

				//Breaks out of switch
				break;

			} //End s case

			default:
			{

				//Checks if the user wants to exit the game
				if(strcmp(str, "exit") == 0)
				{

					return;

				}//End exit case
				else if(strcmp(str, "admin") == 0)
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
							max = 100;

							//Asks the user where they want to go for x
							printf("Enter X\n");
							character->x = errorCheck(&min, &max);

							//Asks the user where they want to go for y
							printf("Enter Y\n");
							character->y = errorCheck(&min, &max);

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
