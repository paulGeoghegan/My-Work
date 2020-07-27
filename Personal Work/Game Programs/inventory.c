
//Header files
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structs.h"
 
//This function will allow the user to manage there inventory
void inventoryManagement()
{

	short option, option2;
	long min, max;

	//Infinite do while loop
	do
	{

		printf("Inventory:\n");

		//Prints all of the items in the users inventory
		for(short i = 0;i < character.currentInventory;i++)
		{

			//Prints item
			printf("%d. %s X %d\n", i+1, inventory[i].name, inventory[i].amount);

		} //End for

		//Asks the user what they want to do
		printf("Enter the corresponding number to an item or enter 0 to exit\n");

		//Sets values for min and max
		min = 0;
		max = character.currentInventory;

		//This gets an imput from the user
		option = errorCheck(&min, &max);

		//Checks what the user wants to do
		if(option == 0)
		{

			//Exits inventory
			printf("Returning to game\n");
			clear();
			return;

		} //End if
		//This will display the details of an item and give the user some options
		else
		{

			//Prints the basic info for the item
			printf("%s\n", inventory[option-1].name);
			printf("%s\n", inventory[option-1].description);
			printf("Value %d\n", inventory[option-1].value);

			//Checks what type of item the user chose
			switch(inventory[option-1].type)
			{

				//This case is for weapons
				case 0:
				{

					//Displays weapon info
					printf("Attack %d\n", inventory[option-1].attack);

					//Displays options
					printf("\n1. Equip\n");

					//Breaks out of case
					break;

				} //End weapon case
				//This case is for armor
				case 1:
				{

					//Displays armor info
					printf("Defence %d\n", inventory[option-1].defence);

					//Displays options
					printf("\n1. Equip\n");

					//Breaks out of case
					break;

				} //End armor case
				//This case is for consumables
				case 2:
				{

					//Displays consumable info
					printf("Attack %d\n", inventory[option-1].attack);
					printf("Defence %d\n", inventory[option-1].defence);
					printf("Health %d\n", inventory[option-1].health);

					//displays options
					printf("\n1. Use\n");

					//Breaks out of case
					break;

				} //End consumables case

			} //End switch for checking item type

		} //End else

		//Checks if the item can be interacted with
		if(inventory[option-1].type != 3)
		{

			//Displays the rest of the menu
			printf("2. Drop\n");

			//Sets value of max
			max = 2;

		} //End if
		else
		{

			//Displays the rest of the menu
			printf("1. Drop\n");

			//Sets value of max
			max = 1;

		} //End else

		//Tells the user how to cancel and leave the menu
		printf("0. cancel\n");

		//Gets an   imput from the user
		option2 = errorCheck(&min, &max);

		//Checks if the user wants to drop an item
		if((option2 == 1 && inventory[option-1].type == 3) || (option2 == 2 && inventory[option-1].type != 3))
		{

			//Asks the user how many they want to drop
			printf("You have %d %s, how many do you want to drop?\nPress 0 to cancel\n", inventory[option-1].amount, inventory[option-1].name);

			//Sets values for min and max
			min = 0;
			max = inventory[option-1].amount;

			//Gets an imput from the user
			option2 = errorCheck(&min, &max);

			//Checks if they want to cancel or drop it
			if(option2 == 0)
			{

				//Lets the user know that it has been canceled
				printf("Canceling\n");

			} //End if
			else
			{

				//Drops the items on to the current map tile
				map[character.y][character.x].itemAmount++;
				//Checks if memory has already been alocated for this tile
				if(map[character.y][character.x].itemAmount == 1)
				{

					//Allocates memory
					map[character.y][character.x].item = (struct mapItem *)calloc(map[character.y][character.x].itemAmount, sizeof(struct mapItem));

				} //End if
				else
				{

					//Re allocates memory
					map[character.y][character.x].item = (struct mapItem *)realloc(map[character.y][character.x].item, (map[character.y][character.x].itemAmount * sizeof(struct mapItem)));

				} //End else

				//Drops item on to the tile
				strncpy((map[character.y][character.x].item+(map[character.y][character.x].itemAmount-1))->name, inventory[option-1].name, sizeof(inventory[0].name));
				(map[character.y][character.x].item+(map[character.y][character.x].itemAmount-1))->amount = option2;
				(map[character.y][character.x].item+(map[character.y][character.x].itemAmount-1))->id = inventory[option-1].id;
				(map[character.y][character.x].item+(map[character.y][character.x].itemAmount-1))->type = inventory[option-1].type;

				//Checks if the user is dropping the whole stack or not
				if(option2 == inventory[option-1].amount)
				{

					//Moves items to make the inventory propperly display its contents
					for(short i = option-1;i < character.currentInventory-1;i++)
					{

						//Coppies properties of item
						strncpy(inventory[i].name, inventory[i+1].name, sizeof(inventory[0].name));
						inventory[i].id = inventory[i+1].id;
						inventory[i].type = inventory[i+1].type;
						inventory[i].amount = inventory[i+1].amount;
						strncpy(inventory[i].description, inventory[i+1].description, sizeof(inventory[0].description));
						inventory[i].attack = inventory[i+1].attack;
						inventory[i].defence = inventory[i+1].defence;
						inventory[i].health = inventory[i+1].health;
						inventory[i].value = inventory[i+1].value;

					} //End for

					//Decreases current inventory size
					character.currentInventory--;

				} //End if
				else
				{

					//Decreases amount by the amount the user chose
					inventory[option-1].amount = inventory[option-1].amount - option2;

				} //End else

			} //End else

		} //End if

		//Clears screen
		clear();

	} //End do while
	while(1);

} //End inventoryManagement
