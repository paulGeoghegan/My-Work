
//Header files
#include <stdio.h>
#include <stdbool.h>
#include "structs.h"

//This function allows the user to pick up an item from the map
void itemPickUp()
{

	bool invCheck = false;
	short i, itemToTake;
	long min, max;

	//Sets values for variables
	itemToTake = 1;

	//Checks if there is any items here
	if(map[character.y][character.x].itemAmount > 0)
	{

		//Checks what item the user wants to pick up
		if(map[character.y][character.x].itemAmount > 1)
		{

			//Asks what item the user wants to pick up
			printf("Which item do you want to pick up?\n");

			//Sets values for min and max
			min = 0;
			max = map[character.y][character.x].itemAmount;

			//Prints out items
			for(i = 0;i < map[character.y][character.x].itemAmount;i++)
			{

				//Prints item
				printf("%d. %s\n", i+1, (map[character.y][character.x].item+i)->name);

			} //End for

			//Gets user imput
			itemToTake = errorCheck(&min, &max);

		} //End if

		//Sets i to 0
		i = 0;

		//checks if the user already has this item
		while((invCheck == false) && (i < character.currentInventory))
		{

			//Checks if items match
			if(((map[character.y][character.x].item+(itemToTake-1))->id == inventory[i].id) && ((map[character.y][character.x].item+(itemToTake-1))->type == inventory[i].type))
			{



			} //End if

		} //End while loop

	} //End if
	else
	{

		//Tells the user that there is nothing to pick up
		printf("There are no items here\n");

	} //End else

} //End itemPickUp
