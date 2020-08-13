
//header files
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include "structs.h"

//Function signatures
void characterGen();
void tiles();
void play();

//This function controlls all of the saving functionality for creating, loading and overwriting
void save(char type)
{

	int check, i, j;
	long min, max;
	char saveLocation[11] = "gameSaves/";
	char tempStr1[21];
	char tempStr2[21];
	char tempStr3[25];
	char tempStr4[25];
	bool exists = false;
	struct dirent *de;
	DIR *dr;
	FILE *characterF, *inventoryF, *mapF, *mapItemsF;
	character.statNames[0] = "Strength"; character.statNames[1] = "Dexterity"; character.statNames[2] = "Constitution"; character.statNames[3] = "Inteligence"; character.statNames[4] = "Wisdom"; character.statNames[5] = "Charisma";

	//This switch case will controll what type of action is being performed
	switch(type)
	{

		//This case will create a new save
		case 'c':
		{

			//tells the user to enter a name for the new save
			printf("Please enter a name for the new save\nThis can be no more than 10 characters\n");

			//gets the save name from the user
			gets(dirName);

			//Opens the gameSaves directory
			dr = opendir("./gameSaves");

			//checks if that directory can be accessed
			if(dr == NULL)
			{

				//Tells the user that it could not be opened
				printf("The gameSaves directory could not be opened. wait one second while it is created...\n");

				//Creates game saves directory
				check = mkdir("gameSaves");

			}

			//sets j to 0
			j = 0;

			//This loops through all of the items in the gameSaves directory
			while(((de = readdir(dr)) != NULL) && exists == false)
			{

				//This makes sure that only the save directories are being checked
				if(j < 2)
				{

					//Adds 1 to j
					j++;

				} //End if
				else
				{

					//Checks if dir already exists
					if(strcmp(dirName, de->d_name) == 0)
					{

						//set exists to true
						exists = true;

						//Lets the user know that that save already exists
						printf("The save %s already exists please enter another name\n", dirName);

					//exits function
					return;

					} //end if

				} //end else

			} //end while

			//closes directory
			closedir(dr);

			//Only creates the new save if it already doesnt exist
			if(exists == false)
			{

				//Tells the user that the new save is being created
				printf("Creating new save\n");

				//concatinates the new name to the gameSaves/ string so that it will be created in the correct directory
				strncat(saveLocation, dirName, 10);

				//Creates new save
				check = mkdir(saveLocation);

				//Coppies saveLocation to 3 strings
				strcpy(tempStr1, saveLocation);
				strcpy(tempStr2, saveLocation);
				strcpy(tempStr3, saveLocation);
				strcpy(tempStr4, saveLocation);

				//Creates character file
				strcat(tempStr1, "/character.dat");
				characterF = fopen(tempStr1, "w");

				//Generates a new character
				characterGen();

				//Writes the character struct to the character save file
				fwrite(&character, sizeof(struct playerCharacter), 1, characterF);

				//Closes the character file
				fclose(characterF);

				//Creates inventory file
				strcat(tempStr2, "/inventory.dat");
				inventoryF = fopen(tempStr2, "w");
				fclose(inventoryF);

				//Creates new directory and changes temp strings
	strcat(tempStr3, "/map");
strcat(tempStr4, "/map");
				check = mkdir(tempStr3);

				//Creates map file
				strcat(tempStr3, "/map.dat");
				mapF = fopen(tempStr3, "w");

				//Generates map
				tiles();

				//Writes the map to the map file
				fwrite(map, offsetof(struct tile, item), (mapSize*mapSize), mapF);

				//Closes map file
				fclose(mapF);

				//Creates map file
				strcat(tempStr4, "/mapItems.dat");
				mapItemsF = fopen(tempStr4, "w");

				//Writes the mapItems to the mapItems file
				//Not yet implamented

				//Closes mapItems file
				fclose(mapItemsF);

				//Closes map directory
				closedir(dr);

				//Lets the user know that a new save has been created
				printf("Finished creating\n");

			} //end if

			//breaks out of case
			break;

		} //end create case
		//This case will load a previous save
		case 'l':
		{

			//Opens directory
			DIR *dr = opendir("./gameSaves");

			//Checks if the directory is accessible
			if(dr == NULL)
			{

				//Tells the user that the directory could not be accessed
				printf("The gameSaves directory could not be opened. Please try again\n");
				return;

			}

			//asks the user which directory they wish to open
			printf("Please choose a save game listed below\n");

			//sets i and j to 0
			i = j = 0;

			//Displays all of the save games in the directory
			while((de = readdir(dr)) != NULL)
			{

				//This stops non save game directories from being printed to the screen
				if(j < 2)
				{

					//Adds 1 to j
					j++;

				} //End if
				else
				{

					//adds 1 to i
					i++;

					//Prints directory
					printf("%d. %s\n", i, de->d_name);

				} //end else

			} //end while

			//closes directory
			closedir(dr);

			//Checks if any directories were listed
			if(i == 0)
			{

				//Lets the user know that there is no saves and returns to the main menu
				printf("There are currently no save games\n");
				return;

			} //End if

			//Tells the user how to exit the menu
			printf("0. Cancel\n");

			//Sets values for min and max
			min = 0;
			max = i;

			//Gets an imput from the user
			i = errorCheck(min, max);

			//Checks if the user wants to exit the menu
			if(i == 0)
			{

				//Returns to main menu
				printf("Exiting...\n");
				return;

			} //End if

			//Sets j to 0
			j = 0;

			//Opens directory
			dr = opendir("./gameSaves");

			//This loop wil select the directory that the user wants to open
			while(((de = readdir(dr)) != NULL) && j <= i+1)
			{

				//Checks if this is the directory that the user chose
				if(j == i+1)
				{

					//Sets dirName to the current directory
					strcpy(dirName, de->d_name);

				} //End if

				//Adds 1 to j
				j++;

			} //end while

			//closes directory
			closedir(dr);

			//Lets the user know that the save game is being loaded
			printf("Loading %s...\n", dirName);

			//Concatinates dirName with saveLocation
			strcat(saveLocation, dirName);

			//Coppies saveLocation to 3 different strings
			strcpy(tempStr1, saveLocation);
			strcpy(tempStr2, saveLocation);
			strcpy(tempStr3, saveLocation);
			strcpy(tempStr4, saveLocation);

			//Opens character file
			strcat(tempStr1, "/character.dat");
			characterF = fopen(tempStr1, "r");

			//Reads file
			fread(&character, sizeof(struct playerCharacter), 1, characterF);

			//Closes character file
			fclose(characterF);

			//Opens inventory file
			strcat(tempStr2, "/inventory.dat");
			inventoryF = fopen(tempStr2, "r");

			//Reads inventory file
			fread(inventory, sizeof(struct items), character.currentInventory, inventoryF);

			//Closes inventory file
			fclose(inventoryF);

			//Changes temp strings for map opening
			strcat(tempStr3, "/map");
			strcat(tempStr4, "/map");

			//Opens map file
			strcat(tempStr3, "/map.dat");
			mapF = fopen(tempStr3, "r");

			//Reads file
			fread(map, offsetof(struct tile, item), mapSize*mapSize, mapF);

			//Closes map file
			fclose(mapF);

			//Opens mapItems file
			strcat(tempStr4, "/mapItems.dat");
			mapItemsF = fopen(tempStr4, "r");

			//Reads mapItems file
			for(register short y = 0;y < mapSize;y++)
			{
				for(register short x = 0;x < mapSize;x++)
				{

					//Allocates memory for items and puts them in the tile
					map[y][x].item = (struct mapItem *)calloc(map[y][x].itemAmount, sizeof(struct mapItem));
					fread(map[y][x].item, sizeof(struct mapItem), map[y][x].itemAmount, mapItemsF);

				} //End for
			} //End for

			//Closes mapItems file
			fclose(mapItemsF);

			//Lets the user know that the save has been loaded
			printf("Loading complete!\n");

			//breaks out of case
			break;

		} //End load case
		//This case will overwrite an existing save with a newer version
		case 's':
		{

			//Concatinates dirName with saveLocation
			strcat(saveLocation, dirName);

			//Coppies saveLocation to 3 different strings
			strcpy(tempStr1, saveLocation);
			strcpy(tempStr2, saveLocation);
			strcpy(tempStr3, saveLocation);
			strcpy(tempStr4, saveLocation);

			//Opens character file
			strcat(tempStr1, "/character.dat");
			characterF = fopen(tempStr1, "w");

			//Reads file
			fwrite(&character, sizeof(struct playerCharacter), 1, characterF);

			//Closes character file
			fclose(characterF);

			//Opens inventory file
			strcat(tempStr2, "/inventory.dat");
			inventoryF = fopen(tempStr2, "w");

			//Writes inventory to file
			fwrite(inventory, sizeof(struct items), character.currentInventory, inventoryF);

			//Closes inventory file
			fclose(inventoryF);

			//Changes temp strings for writing to map
			strcat(tempStr3, "/map");
			strcat(tempStr4, "/map");

			//Opens map file
			strcat(tempStr3, "/map.dat");
			mapF = fopen(tempStr3, "w");

			//writes to map file
			fwrite(map, offsetof(struct tile, item), mapSize*mapSize, mapF);

			//Closes map file
			fclose(mapF);

			//Opens mapItems file
			strcat(tempStr4, "/mapItems.dat");
			mapItemsF = fopen(tempStr4, "w");

			//writes to mapItems file
			for(short y = 0;y < mapSize;y++)
			{
				for(short x = 0;x < mapSize;x++)
				{

					//Checks if there should be any items in this tile
					if(map[y][x].itemAmount != 0)
					{

						//Writes the items in the current tile to the mapItem file
						fwrite(map[y][x].item, sizeof(struct mapItem), map[y][x].itemAmount, mapItemsF);

					} //End if

				} //End for
			}//End for

			//Closes mapItems file
			fclose(mapItemsF);

			//Lets the user know that the save is complete
			printf("Game Saved!\n");

			//Clears screen
			clear();

			//Returns to game
			return;

			//breaks out of case
			break;

		} //End save case

	} //end switch

	//Tells the user how to access the help menu
	printf("At any time you can enter \"HELP\" to access the help menu during the game\n");

	//Clears the screen
	clear();

	//Goes to the play function
	play();

} //end save function
