
//Header files
#include <stdio.h>
#include "structs.h"
 
//This function will allow the user to manage there inventory
void inventoryManagement()
{

	short option;
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
		if(inventory[option-1].type != 2)
		{

			//Displays the rest of the menu
			printf("2. Drop\n");

		} //End if
		else
		{

			//Displays the rest of the menu
			printf("1. Drop\n");

		} //End else

		//Tells the user how to cancel and leave the menu
		printf("0. cancel\n");

		//Changes value of max
		max = 2;

		//Gets an   imput from the user
		option = errorCheck(&min, &max);

		//Clears screen
		clear();

	} //End do while
	while(1);

} //End inventoryManagement