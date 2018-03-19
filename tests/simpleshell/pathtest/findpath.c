#include "holberton.h"
/**
  * findpath - finds the path variable in environmental variable array
  * @env: environmental variable array
  *
  * Return: Pointer to path variable string, or NULL pointer on fail
  */
char *findpath()
{
	char *pathvar;
	int i;
	int findmatch;

	extern char **environ;

	pathvar = NULL;
	i = 0;

	while (environ[i] != NULL)
	{
		findmatch = _strcmp(environ[i]);
		if (findmatch == 1)
		{
			pathvar = environ[i];
			break;
		}
		else
			i++;
	}
	if (pathvar == NULL)
	{
		perror("PATH NOT FOUND");
	}
	return (pathvar);
}
