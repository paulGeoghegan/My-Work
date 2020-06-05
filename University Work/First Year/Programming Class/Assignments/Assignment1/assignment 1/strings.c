#include <stdio.h>

#define MAX 20

int main()
{

	char *str[MAX];
	int x;

	printf("input something");

	fgets(str, MAX, stdin);

	printf("You inputted %s good job\n", str);

	sscanf(str, "%d", &x);

	printf("thats %d", x);

	return 0;
} //end main