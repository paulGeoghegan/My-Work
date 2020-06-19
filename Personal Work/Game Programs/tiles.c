
//header files
#include <string.h>

//Symbolic names
#define tileAmount 5

//structures
struct tile
{
	char name[21];
	short id;
	char description[100];
}; //end tile struct

//Function signatures
void mapGen(int, int, struct tile map[][101], struct tile tileType[tileAmount]);

//This function stores all of the different map tiles in the game
void tiles(int mapSize, struct tile map[][mapSize])
{

	struct tile tileType[tileAmount];

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

mapGen(mapSize, tileAmount, map, tileType);

} //end tiles
