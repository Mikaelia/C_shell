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

	pathvar = NULL;
	i = 0;

	if (env == NULL)
	{
		return(NULL);
	}
	while (env[i] != '\0')
	{
		if (_strcmp(env[i]) > 0)
			pathvar = env[i];
		else
			i++;
	}
	if (pathvar == NULL)
	{
		perror("PATH NOT FOUND");
	}
	return (pathvar);
}
