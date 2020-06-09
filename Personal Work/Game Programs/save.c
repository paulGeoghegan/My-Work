
//header files
#include <stdio.h>
#include <dirent.h>
#include <string.h>

//function signatures
void save(char type)
{

	int check;
	char dirName[11];
	char saveLocation[11] = "gameSaves/";

	switch(type)
	{

		//This case will create a new save
		case 'c':
		{

			//tells the user to enter a name for the new save
			printf("Please enter a name for the new save\nThis can be no more than 10 characters\n");

			//gets the save name from the user
			scanf("%10s", dirName);

			//concatinates the new name to the gameSaves/ string so that it will be created in the correct directory
			strncat(saveLocation, dirName, 10);

			//Creates new save
			check = mkdir(saveLocation);

		} //end create case

	} //end switch

} //end save function

/*
	struct dirent *de;
	DIR *dr = opendir("./gameSaves");
*/