
//header files
#include <string.h>
#include "structs.h"

//Function signatures
void mapGen();

//This function stores all of the different map tiles in the game
void tiles()
{

	//water tile
	strcpy(tileType[0].name, "Water");
	strcpy(tileType[0].description, "You swim through the water as small waves pass you");

	//Grass Land
	strcpy(tileType[1].name, "Grass Land");
	strcpy(tileType[1].description, "You walk through a field of low grass and small flowers");

	//Forest
	strcpy(tileType[2].name, "Forest");
	strcpy(tileType[2].description, "You walk through a dense forest brushing past trees on either side of you");

	//Tundra
	strcpy(tileType[3].name, "Tundra");
	strcpy(tileType[3].description, "A vast expance of ice and snow surounds you");

	//Desert");
	strcpy(tileType[4].name, "Desert");
	strcpy(tileType[4].description, "Sand dunes rise on either side of you as the harsh sun beams down on you");

mapGen();

} //end tiles
