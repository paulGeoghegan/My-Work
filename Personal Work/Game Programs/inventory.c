
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

		//Printf item
		printf("%d. %s\n", i+1, inventory[i].name);

	} //End for

} //End inventoryManagement