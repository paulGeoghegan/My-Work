
//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

//Function signatures
void admin();
void inventoryManagement();
void itemList(short, short, short);
void itemPickUp();
void save(char);

//This function will be where the user actually interacts with the game
void play()
{

	char str[11];
	long min, max;

	//This is the main loop for controlling the game
	do
	{

		//Lets the user know where they are
		printf("%s\n", map[character.y][character.x].name);
		printf("X %d, Y %d\n", character.x, character.y);
		printf("%s\n", map[character.y][character.x].description);

		//Checks if there is an item here
		if(map[character.y][character.x].itemAmount > 0)
		{

			//Tells user what items are there
			for(short i = 0;i < map[character.y][character.x].itemAmount;i++)
			{

				//printS item name
				printf("There are %d %s here\n", (map[character.y][character.x].item+i)->amount, (map[character.y][character.x].item+i)->name);

			} //End for

		} //End if

		printf("To the north is %s\n", map[character.y+1][character.x].name);
		printf("To the south is %s\n", map[character.y-1][character.x].name);
		printf("To the east is %s\n", map[character.y][character.x+1].name);
		printf("To the west is %s\n", map[character.y][character.x-1].name);

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

					//frees memory that had been allocated for the map
					free(map);

					//Leaves the play function
					return;

				}//End exit case
				else if(strcmp(str, "SAVE") == 0)
				{

					//Saves current game state
					save('s');

				} //End else if for saving
				//This will allow the user to view and manage there inventory
				else if(strcmp(str, "INVENTORY") == 0)
				{

					//Prints inventory if there are any items
					if(character.currentInventory >0)
					{

					inventoryManagement();

					} //End if
					else
					{

						//Lets the user know that they currently have nothing in there inventory
					printf("Your inventory is empty\n");

					} //End else

				} //End else if for inventory
				//Allows the user to pick up an item from the map
				else if(strcmp(str, "TAKE") == 0)
				{

					//Goes to the item pick up function
					itemPickUp();

				} //End else if for picking up items
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
					printf("\"INVENTORY\" Allows you to interact with your inventory\n");
					printf("\"SAVE\" allows you to save the game\n");
					printf("\"TAKE\" Allows you to pick up an item\n");

					//Clears screen
					clear();

				} //End else if
				//Admin command
				else if(strcmp(str, "ADMIN") == 0)
				{

					//Goes to the admin function
					admin();

				} //End else if for the admin menu
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
