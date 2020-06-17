
//header files
#include <string.h>

//structures
struct tile
{
	char name[21];
	short id;
	char description[100];
}; //end tile struct

//Symbolic names
#define tileAmount 3

//Function signatures
void mapGen(struct tile map[][101], struct tile tileType[tileAmount], int);

//This function stores all of the different map tiles in the game
void tiles(struct tile map[][101])
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

mapGen(map, tileType, 101);

} //end tiles
