
//Header files
#include <stdio.h>
#include "structs.h"
 
//This function will allow the user to manage there inventory
void inventoryManagement()
{

	printf("Inventory:\n");

	//Prints all of the items in the users inventory
	for(short i = 0;i < character.currentInventory;i++)
	{

		//Prints item
		printf("%d. %s X %d\n", i+1, inventory[i].name, inventory[i].amount);

	} //End for

} //End inventoryManagement