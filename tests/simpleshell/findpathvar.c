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
	char *findmatch;

	extern char **environ;

	pathvar = NULL;
	i = 0;

	while (environ[i] != NULL)
	{
		findmatch = _strcmp_path(environ[i]);
		if (findmatch)
		{
			pathvar = findmatch;
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
