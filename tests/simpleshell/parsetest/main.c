#include "holberton.h"
int  main(void)
{
	char **array;
	int i = 0;

	array = parse("this that other");

	while (array[i] != '\0')
	{
		printf("%s", array[i]);
			i++;
	}
	return (0);
}
