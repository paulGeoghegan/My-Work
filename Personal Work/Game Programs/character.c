
//Header files
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "structs.h"

//This function will create a new character
void characterGen()
{

	bool loop = false;
	long min, max;
	short smallest, smallLocate, temp, k;
	short statGen[4] = {0};
	short statsTemp[6];
	char statNamesTemp[6][13] = {"Strength", "Dexterity", "Constitution", "Inteligence", "Wisdom", "Charisma"};
	srand(time(0));

	//Sets values for x and y so that the user will start in the center of the map
character.x = character.y = mapSize/2;

	//Sets values of minn and max for imput errorChecking()
	min = 1;
	max = 2;

	//This will get the name of the character from the user
	do
	{

		//Asks the user what they want to call there character
		printf("What should your new characters name be?\nThe name can be no longer than 20 characters\n");

		//Gets an imput from the user
		gets(character.name);

		//Checks that the user is happy with this name
		printf("You entered %s is this correct?\n1. Yes\n2. No\n", character.name);

		//Checks if its correct
		switch(errorCheck(&min, &max))
		{

			//Case 1 for correct
			case 1:
			{

				//Changes loop to false
				loop = false;
				break;

			} //End case 1
			//Case 2 for incorrect
			case 2:
			{

				//Changes loop to true
				loop = true;
				break;

			} //End case 2

		} //End switch

	} //End while
	while(loop == true);

	//Sets level and xp of new character
	character.level = 1;
	character.xp = 0;

	//Tells player basic info about there character
	printf("You are %s a level %d character with %d xp\n", character.name, character.level, character.xp);
	clear();

	//Tells the user that there stats will be displayed
	printf("The numbers generated for %s's stats were:\n", character.name);

	//This will generate stats for the user
	for(short i = 0;i < 6;i++)
	{

		//Sets values of smallest and smallLocate
		smallest = smallLocate = 7;

		//Generates numbers for each stat
		for(short j = 0;j < 4;j++)
		{

			//Generates number
			statGen[j] = (rand()%6)+1;

			//This will check which stat is the lowest
			if(statGen[j] < smallest)
			{

				//Changes value of smallest and smallLocate
				smallest = statGen[j];
				smallLocate = j;

			} //End if

		} //End for

		//Checks where the smallest number is
		if(smallLocate != 3)
		{

			//replaces the smallest number with the last element
			statGen[smallLocate] = statGen[3];

		} //End if

		//Calculates value for this stat by using the first 3 values
		statsTemp[i] = statGen[0] + statGen[1] + statGen[2];

		//Prints stat
		printf("%d\n", statsTemp[i]);

	} //End for

	//Clears screen
	clear();

	//This will allow the user to alocate there stats
	for(short i = 6;i > 0;i--)
	{

		//Asks the user where they want to alocate a stat
		printf("Where do you want to allocate your %d\n", statsTemp[i-1]);

		//Prints the stats that have yet to be alocated
		for(short j = 0;j < i;j++)
		{

			//prints stat
			printf("%d. %s\n", j+1, statNamesTemp[j]);

		} //End for

		//Sets values for min and max
		min= 1;
		max = i;

		//Gets an imput from the user
		temp = errorCheck(&min, &max);

		//Sets k to 0
		k = 0;

		//moves selected stat to the character struct and re-aranges statsTemp and statNameTemp arrays
		do
		{

			//Checks if the names match
			if(strcmp(character.statNames[k], statNamesTemp[temp-1]) == 0)
			{

				//Sets loop to false
				loop = false;

				//Stores stat
				character.stats[k] = statsTemp[temp-1];

				//Changes arrays
				for(short l = temp;l < i;l++)
				{

					//Moves name and stat 1 towards 0
					//Moves name and stat 1 towards 0
					strcpy(statNamesTemp[l-1], statNamesTemp[l]);

				} //End for

			} //End if
			else
			{

				//Sets loop to true
				loop = true;

				//Increases k by 1
				k++;

			} //End else

		} //end do while
		while(loop == true);

	} //end for

} //End characterGen
