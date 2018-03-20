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
	tokenlist_t *patharray;
	int i;

	pathvar = findpath();	/*finds PATH string*/
	patharray = pathsplitlist(pathvar);
	i = 0;
	while (patharray[i] != '\0')
	{
		printf("Path at index: %s\n", patharray[i]);
		i++;
	}

	return (0);
}
