
//Header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "structs.h"

//This function will generate a new map
void mapGen()
{

	short x = mapSize/2;
	short y = mapSize/2;
	short xMod, yMod, currentTile, temp, adjaysant;
	srand(time(0));

	//Sets values for xMod and yMod
	xMod = yMod = 1;
	temp = 0;

	//Assignes what tile will be the first on the map
	map[y][x].id = currentTile = (rand()%(tileAmount-1)) +1;
	strncpy(map[y][x].name, tileType[currentTile].name, sizeof(map[0][0].name));
	strncpy(map[y][x].description, tileType[currentTile].description[rand()%desAmount], sizeof(map[0][0].description));
	map[y][x].itemAmount = 0;

	//Lets the user know that the map is being created
	printf("Generating map...\n");

	//This loop wil controll the tile generation
	for(register short i = 3;i < mapSize;i = i+2)
	{

		//Increases value of temp
		temp = i-1;

		//This loop will controll which side is being generated
		for(register short j = 0;j < 4;j++)
		{

			//This switch casemakes sure that x and y Mod have the correct values
			switch(j)
			{

				//This controlls the top side of the spirul
				case 0:
				{

					//Changes values
					xMod = 1;
					yMod = 1;
					adjaysant = -1;
					break;

				} //End case 0
				//This controlls the right side generation of the spirul
				case 1:
				{

					//Changes values
					xMod = -1;
					yMod = -1;
					adjaysant = -1;
					break;

				} //End case 1
				//This controlls the bottom generation of the spirul
				case 2:
				{

					//Changes values
					xMod = -1;
					yMod = 1;
					adjaysant = 1;
					break;

				} //End case 2
				//This controlls the left side of the spirul generation
				case 3:
				{

					//Changes values
					xMod = 0;
					yMod = 1;
					adjaysant = 1;
					break;

				} //End case 3

			} //End switch

			//This will check which direction the generation is going
			if(j == 0 || j == 2)
			{

				//Checks which side the loop is on
				if(j == 0)
				{

					//Increases y
					y = y + yMod;

				} //End if

				//This loop wil set which tiles should be generated in a spirul pattern
				for(register short k = 0;k < temp;k++)
				{

					//Checks if a new tile will be picked or if the previous one will be expanded
					if((k != temp-1) && (rand()%3 != 2))
					{

						//Changes value of currentTile
						currentTile = map[y+adjaysant][x].id;

						//Stores tile
						map[y][x].id = currentTile;
						strncpy(map[y][x].name, tileType[currentTile].name, sizeof(map[0][0].name));
						strncpy(map[y][x].description, tileType[currentTile].description[rand()%desAmount], sizeof(map[0][0].description));
						map[y][x].itemAmount = 0;

					} //End if
					else if(rand()%3 != 2)
					{

						//Stores tile
						map[y][x].id = currentTile;
						strncpy(map[y][x].name, tileType[currentTile].name, sizeof(map[0][0].name));
						strncpy(map[y][x].description, tileType[currentTile].description[rand()%desAmount], sizeof(map[0][0].description));
						map[y][x].itemAmount = 0;

					} //end else 
					else
					{

						//Sets current tile to the new tile type
						currentTile = rand()%tileAmount;

						//Stores tile
						map[y][x].id = currentTile;
						strncpy(map[y][x].name, tileType[currentTile].name, sizeof(map[0][0].name));
						strncpy(map[y][x].description, tileType[currentTile].description[rand()%desAmount], sizeof(map[0][0].description));
						map[y][x].itemAmount = 0;

					} //End if

					//Adds xMod to x
					x = x + xMod;

				} //End for

				//Decreases x by one
				x = x + xMod*-1;;

				//Checks which side the loop is on
				if(j == 2)
				{

					//Increases y
					y = y + yMod;

				} //End if

			} // End if
			else if(j == 1 || j == 3)
			{

				//Checks which side the loop is on
				if(j == 1)
				{

					//Increases y
					y = y + yMod;

				} //End if

				//This loop wil set which tiles should be generated in a spirul pattern
				for(short k = 0;k < temp;k++)
				{

					//Checks if a new tile will be picked or if the previous one will be expanded
					if((k != temp-1) && (rand()%3 != 2))
					{

						//Changes value of currentTile
						currentTile = map[y][x+adjaysant].id;

						//Stores tile
						map[y][x].id = currentTile;
						strncpy(map[y][x].name, tileType[currentTile].name, sizeof(map[0][0].name));
						strncpy(map[y][x].description, tileType[currentTile].description[rand()%desAmount], sizeof(map[0][0].description));
						map[y][x].itemAmount = 0;

					} //End if
					else if(rand()%3 != 2)
					{

						//Stores tile
						map[y][x].id = currentTile;
						strncpy(map[y][x].name, tileType[currentTile].name, sizeof(map[0][0].name));
						strncpy(map[y][x].description, tileType[currentTile].description[rand()%desAmount], sizeof(map[0][0].description));
						map[y][x].itemAmount = 0;

					} //end else
					else
					{

						//Sets current tile to the new tile type
						currentTile = rand()%tileAmount;

						//Stores tile
						map[y][x].id = currentTile;
						strncpy(map[y][x].name, tileType[currentTile].name, sizeof(map[0][0].name));
						strncpy(map[y][x].description, tileType[currentTile].description[rand()%desAmount], sizeof(map[0][0].description));
						map[y][x].itemAmount = 0;

					} //End if

					//Adds yMod to y
					y = y+yMod;

				} //End for

				//Changes value of y
				y = y + yMod*-1;

				//Checks which side the loop is on
				if(j == 1)
				{

					//Increases x
					x = x + xMod;

				} //End if

			} //End else if
			else
			{

				//Lets the user know that something has gone wrong
				printf("Something has gone wrong\n");
				return;

			} //End else

		} //End for

	} //End for

	//Sets x and y for use in following loop
	x = 0;
	y = 0;

	//This loop will add a border of water tiles to the map along the y axis
	for(short i = 0;i < 2;i++)
	{

		//Adds tiles to the left and right side of the map
		for(short j = 0;j < mapSize;j++)
		{

			//Adds tile
			map[j][x].id = 0;
			strncpy(map[j][x].name, tileType[0].name, sizeof(map[0][0].name));
			strncpy(map[j][x].description, tileType[0].description[rand()%desAmount], sizeof(map[0][0].description));
			map[y][x].itemAmount = 0;

		} //End for

		//Changes value of x
		x = mapSize-1;

	} //End for

	//This loop will add a border of water tiles to the map along the x axis
	for(short i = 0;i < 2;i++)
	{

		//Adds tiles to the left and right side of the map
		for(short j = 0;j < mapSize;j++)
		{

			//Adds tile
			map[y][j].id = 0;
			strncpy(map[y][j].name, tileType[0].name, sizeof(map[0][0].name));
			strncpy(map[y][j].description, tileType[0].description[rand()%desAmount], sizeof(map[0][0].description));
			map[y][x].itemAmount = 0;

		} //End for

		//Changes value of y
		y = mapSize-1;

	} //End for

	//This will add random items to the map
	

	//Lets the user know the map has been generated
	printf("Map generated\n");

} //End mapGen
