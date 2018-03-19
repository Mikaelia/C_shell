#include "holberton.h"
/**
  * findpath - finds the path variable in environmental variable array
  * @env: environmental variable array
  *
  * Return: Pointer to path variable string, or NULL pointer on fail
  */
char *findpath(char **env)
{
	char *pathvar;
	int i;
	int findmatch;

	pathvar = NULL;
	i = 0;

	while (env[i] != NULL)
	{
		findmatch = _strcmp(env[i]);
		if (findmatch == 1)
		{
			pathvar = env[i];
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
