
//Header files
#include <stdio.h>
#include <string.h>
#include "structs.h"

//Function signatures
void save(char);
void itemList(short, short, short);

void play()
{

	char str[11];
	long min, max;
	short temp, itemType, itemId, itemLocation;

	//This is the main loop for controlling the game
	do
	{

		//Lets the user know where they are
		printf("%s\n", map[character.y][character.x].name);
		printf("X %d, Y %d\n", character.x, character.y);
		printf("%s\n", map[character.y][character.x].description);
		printf("To the north you can see a %s\n", map[character.y+1][character.x].name);
		printf("To the south is a %s\n", map[character.y-1][character.x].name);
		printf("To the east is a %s\n", map[character.y][character.x+1].name);
		printf("To the west is a %s\n", map[character.y][character.x-1].name);

		//Gets an imput from the user
		gets(str);

		//Switch to run through all the options
		switch(str[0])
		{

			//moves upwards in the y direction
			case 'w':
			{

				//Makes sure movement wont let user move outside of the map
				if((character.y + 1) < mapSize)
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
				if((character.x + 1) < mapSize)
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
				if(strcmp(str, "EXIT") == 0)
				{

					//Lets the user know that they are leaving the game
					printf("Exiting game...\n");

					//Leaves the play function
					return;

				}//End exit case
				else if(strcmp(str, "SAVE") == 0)
				{

					//Saves current game state
					save('s');

				} //End else if for saving
				//Help command
				else if(strcmp(str, "HELP") == 0)
				{

					//Gives the user a list of commands
					printf("The following is the lfull list of in game commands\n");
					printf("\"w\" Allows you to move upwards in the y direction\n");
					printf("\"s\" Allows you to move downwards in the y direction\n");
					printf("\"d\" Allows you to move upwards in the x direction\n");
					printf("\"a\" Allows you to move downwards in the x direction\n");
					printf("\"EXIT\" Allows you to exit the game\n");
					printf("\"SAVE\" allows you to save the game\n");
					printf("\"HELP\" Allows the help menu to be displayed\n");

					//Clears screen
					clear();

				} //End else if
				//Admin command
				else if(strcmp(str, "ADMIN") == 0)
				{

					//Tells the user that they have entered the admin menu
					printf("Admin menu:\n");
					printf("1. teleport\n");
					printf("2. get item\n");

					//Sets values for min and max
					min = 1;
					max = 2;

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
						//This allows the user to return an item
						case 2:
						{

							//Asks the user for the type of the item
							printf("Enter the item type\n");

							//Sets values for min and max
							min = 0;
							max = 1000000;

							//Gets itemType
							itemType = errorCheck(&min, &max);

							//Asks the user for the itemId
							printf("Enter the item id\n");

							//Gets itemId
							itemId = errorCheck(&min, &max);

							//Checks if the users inventory is full
							if(character.currentInventory == inventorySize)
							{

								//Asks the user where they want to put the item
								printf("Where do you want this item to go in your inventory\nEnter a value from 0 to %d\nAny item in this slot will be destroyed\n", inventorySize-1);

								//Sets value for max
								max = inventorySize - 1;

								//Gets value for itemLocation
								itemLocation = errorCheck(&min, &max);

							} //End if
							else
							{

								//Sets value for itemLocation
								itemLocation = character.currentInventory;

								//

							} //End else

							//This gets the item
							itemList(itemType, itemId, itemLocation);

							//Breaks out of item case
							break;

						} //End item case
						default:
						{

							//Lets the user know that that wasnt a valid option
							printf("That was not a valid option\n");

						} //End default case

					} //End admin switch

				} //End else if
				else
				{

					//Tells the user that that was not a valid imput
					printf("That was not a valid option please try again\n");
					clear();

				} //End else

			} //End default case

		} //End switch

	} //End do while
	while(1);

} //End play
