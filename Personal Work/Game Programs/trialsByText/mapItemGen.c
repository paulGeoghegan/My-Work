
//Header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structs.h"

void mapItemGen()
{

	short x, y, itemGenAmount, itemToGen, itemId, itemType, itemAmount, exists;
	char itemName[21];
	srand(time(0));

	//Lets the user know that items are being added to the map
	printf("Adding items to the map...\n");

	//Sets value for itemGenAmount
	itemGenAmount = ((mapSize-1) / 5) + ((rand()%20) - 10);

	//This will add random items to the map
	for(short i = 0;i < itemGenAmount;i++)
	{

		//Generates item probability and coardinates for it
		itemToGen = (rand()%100)+1;
		x = rand()%mapSize;
		y = rand()%mapSize;

printf("I is %d\n", i);
printf("X %d, Y %d\n", x, y);
getchar();

		//Checks which item is being generated
		if(itemToGen < 2)
		{

			//Generates dirty gem
			strncpy(itemName, "Dirty Gem", sizeof(itemName));
			itemType = 3;
			itemId = 3;
			itemAmount = 1;

		} //End if
		else if(itemToGen < 21)
		{

			//Generates bone
			strncpy(itemName, "Bone", sizeof(itemName));
			itemType = 3;
			itemId = 2;
			itemAmount = 1;

		} //End else if
		else if(itemToGen < 51)
		{

			//Generates wood plank
			strncpy(itemName, "Wood Plank", sizeof(itemName));
			itemType = 3;
			itemId = 1;
			itemAmount = 1;

		} //End else if
		else if(itemToGen < 101)
		{

			//Generates plant
			strncpy(itemName, "Plant", sizeof(itemName));
			itemType = 3;
			itemId = 0;
			itemAmount = 1;

		} //End else if
		else
		{

			//Lets the user know that something has gone wrong
			printf("Something has gone wrong while generating items!\n");

		} //End else

		//Checks if memory has already been alocated for this tile for item storage
		if(map[y][x].itemAmount == 0)
		{

			//Allocates memory
			map[y][x].item = (struct mapItem *)calloc(map[y][x].itemAmount, sizeof(struct mapItem));

			//Coppies properties to tile
			strncpy((map[y][x].item)->name, itemName, sizeof(itemName));
			(map[y][x].item)->type = itemType;
			(map[y][x].item)->id = itemId;
			(map[y][x].item)->amount = itemAmount;

			//Increases itemAmount for the current tile
			map[y][x].itemAmount++;

		} //End if
		else
		{

			//Sets exists to 0
			exists = 0;

			//This loop will check if this item is already in this tile
			for(short i = 0;i < map[y][x].itemAmount;i++)
			{

				//Adds 1 to the item amount in the tile if this item already exists
				if(itemId == (map[y][x].item+i)->id)
				{

					//Adds 1 to amount
					(map[y][x].item+i)->amount++;

					//Changes value of exists to 1
					exists = 1;

				} //End if

			} //End for

			//Checks if exists = 0
			if(exists == 0)
			{

				//Increases value of itemAmount for this tile
				map[y][x].itemAmount++;

				//reallocates memory
				map[y][x].item = (struct mapItem *)realloc(map[y][x].item, (map[y][x].itemAmount * sizeof(struct mapItem)));

				//Coppies properties of item
				strncpy((map[y][x].item+(map[y][x].itemAmount-1))->name, itemName, sizeof(itemName));
				(map[y][x].item+(map[y][x].itemAmount-1))->type = itemType;
				(map[y][x].item+(map[y][x].itemAmount-1))->id = itemId;
				(map[y][x].item+(map[y][x].itemAmount-1))->amount = itemAmount;

			} //End if

		} //End else

	} //End for

	//Lets the user know that the items have been added to the map
	printf("Items added\n");

} //End mapItemGen
