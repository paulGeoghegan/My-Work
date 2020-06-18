
//Header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Symbolic names
#define tileAmount 3

//Structures
struct tile
{
	char name[21];
	short id;
	char description[100];
}; //End tile struct

//This function will generate a new map
void mapGen(struct tile map[][101], struct tile tileType[3], int mapSize)
{

	short x = mapSize / 2;
	short y = mapSize / 2;
	short xMod, yMod, currentTile, temp;
	srand(time(0));

	//Sets values for xMod and yMod
	xMod = yMod = 1;
	temp = 0;

	//Assignes what tile will be the first on the map
	map[y][x].id = currentTile = (rand()%(tileAmount-1)) +1;
	strcpy(map[y][x].name, tileType[currentTile].name);
	strcpy(map[y][x].description, tileType[currentTile].description);

	//Lets the user know that the map is being created
	printf("Generating map...\n");

	//This loop wil controll the tile generation
	for(short i = 3;i < mapSize;i = i+2)
	{

		//Increases value of temp
		temp = temp+2;

		//This loop will controll which side is being generated
		for(short j = 0;j < 4;j++)
		{

			//This switch casemakes sure that x and y Mod have the correct values
			switch(j)
			{

				//This controlls the top side of the spirul
				case 0:
				{

					//Changes values
					xMod = 1;
					yMod = 0;
					break;

				} //Ed case 0
				//This controlls the right side generation of the spirul
				case 1:
				{

					//Changes values
					xMod = -1;
					yMod = -1;
					break;

				} //End case 1
				//This controlls the bottom generation of the spirul
				case 2:
				{

					//Changes values
					xMod = -1;
					yMod = 1;
					break;

				} //End case 2
				//This controlls the left side of the spirul generation
				case 3:
				{

					//Changes values
					xMod = 0;
					yMod = 1;
					break;

				} //End case 3

			} //End switch

			//This will check which direction the generation is going
			if(j == 0 || j == 2)
			{

				//Changes value of y
				y = y+yMod;

				//This loop wil set which tiles should be generated in a spirul pattern
				for(short k = 0;k < temp;k++)
				{

					//Checks if a new tile will be picked or if the previous one will be expanded
					if(rand()%5 == 4)
					{

						//Sets current tile to the new tile type
						currentTile = rand()%tileAmount;

						//Stores tile
						map[y][x].id = currentTile;
						strcpy(map[y][x].name, tileType[currentTile].name);
						strcpy(map[y][x].description, tileType[currentTile].description);

					} //End if
					else
					{

						//Stores tile
						map[y][x].id = currentTile;
						strcpy(map[y][x].name, tileType[currentTile].name);
						strcpy(map[y][x].description, tileType[currentTile].description);

					} //end else 

					//Adds xMod to x
					x = x + xMod;

				} //End for

			} // End if
			else if(j == 1 || j == 3)
			{

				//This loop wil set which tiles should be generated in a spirul pattern
				for(short k = 0;k < temp;k++)
				{

					//Checks if a new tile will be picked or if the previous one will be expanded
					if(rand()%5 == 4)
					{

						//Sets current tile to the new tile type
						currentTile = rand()%tileAmount;

						//Stores tile
						map[y][x].id = currentTile;
						strcpy(map[y][x].name, tileType[currentTile].name);
						strcpy(map[y][x].description, tileType[currentTile].description);

					} //End if
					else
					{

						//Stores tile
						map[y][x].id = currentTile;
						strcpy(map[y][x].name, tileType[currentTile].name);
						strcpy(map[y][x].description, tileType[currentTile].description);

					} //end else

					//Adds yMod to y
					y = y+yMod;

				} //End for

				//Changes value of x
				x = x+xMod;

			} //End else if
			else
			{

				//Lets the user know that something has gone wrong
				printf("Something has gone wrong\n");
				return;

			} //End else

		} //End for

	} //End for

	//Lets the user know the map has been generated
	printf("Map generated\n");

} //End mapGen


//This function will return a map from a game save
void mapRet()
{

} //End mapRet
