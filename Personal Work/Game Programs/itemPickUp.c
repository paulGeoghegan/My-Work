
//Header files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "structs.h"

//Function signatures
void itemList(short, short, short, short);

//This function allows the user to pick up an item from the map
void itemPickUp()
{

	bool invCheck = false;
	short i, itemToTake;
	long min, max;

	//Sets values for variables
	itemToTake = 1;
	invCheck = false;

	//Checks if there is any items here
	if(map[character.y][character.x].itemAmount > 0)
	{

		//Checks what item the user wants to pick up
		if(map[character.y][character.x].itemAmount > 1)
		{

			//Asks what item the user wants to pick up
			printf("Which item do you want to pick up?\n");

			//Sets values for min and max
			min = 1;
			max = map[character.y][character.x].itemAmount+1;

			//Prints out items
			for(i = 0;i < map[character.y][character.x].itemAmount;i++)
			{

				//Prints item
				printf("%d. %s\n", i+1, (map[character.y][character.x].item+i)->name);

			} //End for

			//Gets user imput
			itemToTake = errorCheck(min, max);

		} //End if

		//Sets i to 0
		i = 0;

		//checks if the user already has this item
		while((invCheck == false) && (i <= character.currentInventory))
		{

			//Checks if items match
			if(((map[character.y][character.x].item+(itemToTake-1))->id == inventory[i].id) && ((map[character.y][character.x].item+(itemToTake-1))->type == inventory[i].type))
			{

				//Changes value of invCheck
				invCheck == true;

			} //End if
			else
			{

				//Adds 1 to i
				i++;

			} //End else

		} //End while loop

		//This checks if the user already has this item
		if(invCheck == false)
		{

			//checks if theres space in the users inventory
			if(character.currentInventory < inventorySize)
			{

				//Puts the item in the users inventory
				itemList((map[character.y][character.x].item+(itemToTake-1))->type, (map[character.y][character.x].item+(itemToTake-1))->id, (map[character.y][character.x].item+(itemToTake-1))->amount, i);

				//Increases value of currentInventory
				character.currentInventory++;

				//Decreases amount of items on the current map tile
				(map[character.y][character.x].item+(itemToTake-1))->amount--;

				//Reallocates memory
				map[character.y][character.x].item = (struct mapItem *)realloc(map[character.y][character.x].item, (map[character.y][character.x].itemAmount * sizeof(struct mapItem)));

			} //End if
			else
			{

				//Lets the user know that they have no space in there inventory
				printf("There is not enough space in your inventory to pick up the item\n");
				return;

			} //End else

		} //End if
		else
		{

			//Adds item amount to inventory
			inventory[i].amount = inventory[i].amount + (map[character.y][character.x].item+(itemToTake-1))->amount;

		} //End else

	} //End if
	else
	{

		//Tells the user that there is nothing to pick up
		printf("There are no items here\n");
		return;

	} //End else

	//Lets the user know what was added to there inventory
	printf("%d %s Have been added to your inventory\n", (map[character.y][character.x].item+(itemToTake-1))->amount, inventory[i].name);

} //End itemPickUp
