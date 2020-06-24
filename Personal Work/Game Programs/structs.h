
//Header files
#include <stdbool.h>

//Symbolic names
#define mapSize 301
#define tileAmount 5

//Structures
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

struct items
{
	char name[21];
	short id;
	short amount;
	char description[100];
	bool equipable;
	bool equiped;
	short attack;
	short defence;
	short value;
}; //End item structure

struct tile
{
	char name[21];
	short id;
	char description[100];
}; //End tile struct

//Function signatures
long errorCheck(long*, long*);
void clear();
void end();

//Struct global variables
struct playerCharacter character;
struct tile map[mapSize][mapSize];
struct tile tileType[tileAmount];

//File name global variable
char dirName[11];
