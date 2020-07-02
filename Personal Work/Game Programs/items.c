
//Header files
#include <stdio.h>
#include <string.h>
#include "structs.h"

void itemList(short itemType, short itemId, short itemLocation)
{

	//Checks if this item is already in the users inventory
	for(short i = 0;i < character.currentInventory;i++)
	{

		//Checks if the user already has this item
		if((itemType == inventory[i].type) && (itemId == inventory[i].id))
		{

			//Increases amount
			inventory[i].amount++;

			//Exits itemList function
			return;

		} //End if

	} //End for

	//This switch will check what type of item is needed and then find the item
	switch(itemType)
	{

		//This case will return a weapon
		case 0:
		{

			//Sets item type
			inventory[itemLocation].type = 0;

			//This switch will get the weapon
			switch(itemId)
			{

				//This case will generate a dagger
				case 0:
				{

					//Saves properties of the dagger
					strcpy(inventory[itemLocation].name, "Dagger");
					inventory[itemLocation].amount = 1;
					strcpy(inventory[itemLocation].description, "A small blade that can be easily hidden");
					inventory[itemLocation].value = 5;
					inventory[itemLocation].attack = 4;

					//Increases value of currentInventory
					character.currentInventory++;

					//This breaks out of the case
					break;

				} //End case 0
				default:
				{

					//Lets the user know that that weapon does not exist
					printf("A weapon with the id %d does not exist\n", itemId);

				} //End default case

			} //End weapon switch

			//This breaks out of the weapon case
			break;

		} //End case 0 for weapons
		//This case will return armor
		case 1:
		{

			//Sets item type
			inventory[itemLocation].type = 1;

			//This switch will get the armor
			switch(itemId)
			{

				//This case will get leather armor
				case 0:
				{

					//Coppies properties of leather armor
					strcpy(inventory[itemLocation].name, "Leather Armor");
					inventory[itemLocation].amount = 1;
					strcpy(inventory[itemLocation].description, "A basic set of leather armor");
					inventory[itemLocation].value = 10;
					inventory[itemLocation].defence = 11;

					//Increases value of currentInventory
					character.currentInventory++;

					//This breaks out of the case
					break;

				} //End case 0
				default:
				{

					//Lets the user know that that armor does not exist
					printf("An armor with the id %d does not exist\n", itemId);

				} //End default case

			} //End armor switch

			//This breaks out of the armor case
			break;

		} //End case 1 for armor
		//This case will return a consumable
		case 2:
		{

			//Sets item type
			inventory[itemLocation].type = 2;

			//This switch will get the consumable
			switch(itemId)
			{

				//Gets health potion
				case 0:
				{

					//Coppies properties of health potion
					strcpy(inventory[itemLocation].name, "Health Potion");
					inventory[itemLocation].amount = 1;
					strcpy(inventory[itemLocation].description, "A vile full of a red sparkling liquid");
					inventory[itemLocation].attack = 0;
					inventory[itemLocation].defence = 0;
					inventory[itemLocation].health = 5;
					inventory[itemLocation].value = 25;

					//Increases value of currentInventory
					character.currentInventory++;

					//This breaks out of the case
					break;

				} //End case 0
				default:
				{

					//Lets the user know that that weapon does not exist
					printf("A consumable with the id %d does not exist\n", itemId);

				} //End default case

			} //End consumable switch

			//This breaks out of the consumable case
			break;

		} //End case 2 for getting consumables
		//This case will return all other items
		case 3:
		{

			//Sets item type
			inventory[itemLocation].type = 3;

			//This switch will get the item
			switch(itemId)
			{

				//Gets wood plank
				case 0:
				{

					//Coppies properties of wood plank
					strcpy(inventory[itemLocation].name, "Wood Plank");
					inventory[itemLocation].amount = 1;
					strcpy(inventory[itemLocation].description, "A small wooden plank");
					inventory[itemLocation].value = 1;

					//Increases value of currentInventory
					character.currentInventory++;

					//This breaks out of the case
					break;

				} //End case 0
				default:
				{

					//Lets the user know that that item does not exist
					printf("An item with the id %d does not exist\n", itemId);

				} //End default case

			} //End item switch

			//This breaks out of the item case
			break;

		}
		//This lets the user know that that item couldnt be found
		default:
		{

			//Tells the user that that item cant be found
			printf("The item with type %d and id %d does not exist\n", itemType, itemId);

		} //End default

	} //End switch for finding item types

} //End inventory
