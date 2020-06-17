
//Header files
#include <stdio.h>
#include <stdbool.h>

//Structures
struct items
{
	char name[21];
	short id;
	short amount;
	char description[100];
	bool equipable;
	short attack;
	short defence;
	short value;
}; //End item structure

void itemList(struct items item)
{

	printf("Test\n");

} //End inventory