
//header files
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

//Structures
struct playerCharacter
{
	char name[21];
	short level;
	int xp;
	char *statNames[6];
	short stats[6];
}; //End playerCharacter

//Function signatures
void characterGen(struct playerCharacter *character);
void mapGen(short[][101], int);

//Utility functions
long errorCheck(long*, long*);

//This function controlls all of the saving functionality for creating, loading and overwriting
void save(char type)
{

	int check, i, j;
	char dirName[11];
	long min, max;
	char saveLocation[11] = "gameSaves/";
	char tempStr1[21];
	char tempStr2[21];
	char tempStr3[21];
	bool exists = false;
	struct dirent *de;
	DIR *dr;
	FILE *characterF, *inventoryF, *mapF;
	int mapSize = 101;
	short map[mapSize][mapSize];
	struct playerCharacter character;
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
				printf("The gameSaves directory could not be opened. Please try again\n");
				return;

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

				//Creates character file
				strcat(tempStr1, "/character.dat");
				characterF = fopen(tempStr1, "w");

				//Generates a new charactera
				characterGen(&character);

				//Writes the character struct to the character save file
				fwrite(&character, sizeof(struct playerCharacter), 1, characterF);

				//Closes the character file
				fclose(characterF);

				//Creates inventory file
				strcat(tempStr2, "/inventory.dat");
				inventoryF = fopen(tempStr2, "w");
				fclose(inventoryF);

				//Creates map file
				strcat(tempStr3, "/map.dat");
				mapF = fopen(tempStr3, "w");

				//Generates map
				mapGen(map, mapSize);

				//Writes the map to the map file
fwrite(map, sizeof(short), (mapSize*mapSize), mapF);

				//Closes the map file
				fclose(mapF);

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

			//sets i to 0
			i = 0;
			j = 0;

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
					printf("%d, %s\n", i, de->d_name);

				} //end else

			} //end while

			//closes directory
			closedir(dr);

			//Sets values for min and max
			min = 0;
			max = i+2;

			//Gets an imput from the user
			i = errorCheck(&min, &max) + 2;

			//Sets j to 0
			j = 0;

			//Opens directory
			dr = opendir("./gameSaves");

			//This loop wil select the directory that the user wants to open
			while(((de = readdir(dr)) != NULL) && j < i)
			{

				//Checks if this is the directory that the user chose
				if(j == i-1)
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

			//Opens character file
			strcat(tempStr1, "/character.txt");
			characterF = fopen(tempStr1, "r");

			//Opens inventory file
			strcat(tempStr2, "/inventory.txt");
			inventoryF = fopen(tempStr2, "r");

			//Opens map file
			strcat(tempStr3, "/map.txt");
			mapF = fopen(tempStr3, "r");

			//Lets the user know that the save has been loaded
			printf("Loading complete!\n");

			//breaks out of case
			break;

		} //End load case

	} //end switch

} //end save function
