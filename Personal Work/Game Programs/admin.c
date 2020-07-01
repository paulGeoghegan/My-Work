
//Header files
#include <stdio.h>
#include "structs.h"

//Function signatures
void itemList(short, short, short);

//This function allows the user to exicute admin only actions
void admin()
{

	short itemType, itemId, itemLocation;
	long min, max;
	char str[11];

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

} //End admin function
