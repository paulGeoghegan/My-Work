
//Header files
#include <stdio.h>

//Symbolic names
#define mapSize 101
struct playerCharacter
{
	char name[21];
	short level;
	int xp;
	char *statNames[6];
	short stats[6];
	short x;
	short y;
}; //End playerCharacter

struct tile
{
	char name[21];
	short id;
	char description[100];
}; //End tile struct

void play(struct playerCharacter *character, struct tile map[][mapSize], char dirName[])
{

	printf("%s", dirName);
getchar();

} //End play
