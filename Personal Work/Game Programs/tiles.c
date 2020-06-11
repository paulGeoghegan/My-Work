
//header files
#include <string.h>

//structures
struct tile
{
	char *name;
	char description[100];
}; //end tile struct

//Symbolic names
#define tileAmount 3

//Global tiles array
	struct tile tl[tileAmount];

//This function stores all of the different map tiles in the game
void tiles(short i)
{

	//water tile
	strcpy(tl[0].name, "Water");
	strcpy(tl[0].description, "You swim through the water as small waves pass you");

	//Grass Land
	strcpy(tl[1].name, "Grass Land");
	strcpy(tl[1].description, "You walk through a field of low grass and small flowers");

	//Forest
	strcpy(tl[2].name, "Forest");
	strcpy(tl[2].description, "You walk through a dense forest brushing past trees on either side of you");

} //end map
