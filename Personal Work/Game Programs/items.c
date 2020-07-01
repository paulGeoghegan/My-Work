
//Header files
#include <stdio.h>
#include <string.h>
#include "structs.h"

void itemList(short itemType, short itemId, short itemLocation)
{

	//This switch will check what type of item is needed and then find the item
	switch(itemType)
	{

		//This case will return a weapon
		case 0:
		{

			//This switch will get the weapon
			switch(itemId)
			{

				//Case 0:
				{

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



			//This switch will get the armor
			switch(itemId)
			{

				//Case 0:
				{

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



			//This switch will get the consumable
			switch(itemId)
			{

				//Case 0:
				{

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



			//This switch will get the item
			switch(itemId)
			{

				//Case 0:
				{

					//This breaks out of the case
					break;

				} //End case 0
				default:
				{

					//Lets the user know that that weapon does not exist
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
