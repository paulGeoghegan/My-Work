
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
	strcpy(tileType[0].description[0], "You swim through the water as small waves pass you");
	strcpy(tileType[0].description[1], "You can feel the water soking your cloaths as you trudge through it");
	strcpy(tileType[0].description[2], "The hard ground falls away under your feet as you find yourself floating in the water");

	//Grass Land
	strcpy(tileType[1].name, "Grass Land");
	strcpy(tileType[1].description[0], "You walk through a field of low grass and small flowers");
	strcpy(tileType[1].description[1], "Blades of grass rub against you as you make your way through the green expanse");
	strcpy(tileType[1].description[2], "The tall grass bends in the wind revealing yet more grass behind it");

	//Forest
	strcpy(tileType[2].name, "Forest");
	strcpy(tileType[2].description[0], "You walk through a dense forest brushing past trees on either side of you");
	strcpy(tileType[2].description[1], "Roots larger than you sprawl out across the leaf covered ground");
	strcpy(tileType[2].description[2], "The trunks of trees reach high in to the sky and then branch out in to a all covering canapy");

	//Tundra
	strcpy(tileType[3].name, "Tundra");
	strcpy(tileType[3].description[0], "A vast expance of ice and snow surounds you");
	strcpy(tileType[3].description[1], "There is nothing here but cold and thick slabs of ice");
	strcpy(tileType[3].description[2], "The ice here is filled with cracks which you try your best to avoid");

	//Desert
	strcpy(tileType[4].name, "Desert");
	strcpy(tileType[4].description[0], "Sand dunes rise on either side of you as the harsh sun beams down on you");
	strcpy(tileType[4].description[1], "Planes of glittering sand stretch out on either side of you");
	strcpy(tileType[4].description[2], "The sun seems to be coming from every direction as it reflects off the sand around you");

} //end tiles
