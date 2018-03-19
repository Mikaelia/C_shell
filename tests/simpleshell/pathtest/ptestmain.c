#include "holberton.h"
/**
  * main - main function for simple shell
  *
  *
  *
  */
int main (void)
{
	char *pathvar;
	char **patharray;
	int i;

	pathvar = findpath();	/*finds PATH string*/
	patharray = pathsplit(pathvar);
	i = 0;
	while (patharray[i] != '\0')
	{
		printf("Path at index: %s\n", patharray[i]);
		i++;
	}

	return (0);
}
