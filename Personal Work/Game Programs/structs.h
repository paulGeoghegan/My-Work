
//Symbolic names
#define mapSize 301
#define tileAmount 5
#define desAmount 3
#define inventorySize 30

//Structures
//This struct will hold all values related to the player character
struct playerCharacter
{
	char name[21];
	short level;
	int xp;
	char *statNames[6];
	short stats[6];
	short x;
	short y;
	short currentInventory;
}; //End playerCharacter

//This struct will store values for items
struct items
{
	char name[21];
	short id;
	short type;
	short amount;
	char description[51];
	short attack;
	short defence;
	short health;
	short value;
}; //End item structure

//This struct will be used to store item data in the map
struct mapItem
{
	char name[21];
	short id;
	short type;
	short amount;
}; //End mapItem

//This struct will be used for map generation and storage
struct tile
{
	char name[21];
	short id;
	char description[100];
	short itemAmount;
	struct mapItem *item;
}; //End tile struct

//This struct will hold the templates for every tile
struct tileTemp
{
	char name[21];
	short id;
	char description[desAmount][100];
}; //End tileTemp struct

//Function signatures
long errorCheck(long*, long*);
void clear();
void end();

//Struct global variables
struct playerCharacter character;
struct tile map[mapSize][mapSize];
struct tileTemp tileType[tileAmount];
struct items inventory[inventorySize];

//File name global variable
char dirName[11];
