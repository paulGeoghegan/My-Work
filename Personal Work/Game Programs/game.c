/*
	Description
This will be a text based game written in C
More information will be added as the program is developed
	Author
Paul Geoghegan
	Date
08/06/20
*/

//Header files
#include <stdio.h>
#include <dirent.h>
#include <string.h>

//function signatures
void save(char);

int main()
{

	short option;

	do
	{

		printf("Main menu\n");
		printf("Please select 1 of the following options by entering the corosponding number\n");
		printf("1. Create New Game\n");
		printf("2. Load An Existing Game\n");

		scanf("%d", &option);

		switch(option)
		{

			//this case will create a new save
			case 1:
			{

				save('c');

			} //end case 1

		} //end switch

	} //end do while
	while(1);

	return 0;
} //end main

/*
	if(dr == NULL)
	{

		printf("Could not open current directory");
		return 0;
	}

	while((de = readdir(dr)) != NULL)
	closedir(dr);
	{
		printf("%s\n", de->d_name);
	} //end while
*/