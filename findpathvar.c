#include "holberton.h"
/**
 * path_match - searches env variable strings for PATH name
 * @envar: environmental variable to compare
 *
 * Return: 1 on match, -1 if no match found
 */
char *path_match(char *envar)
{
	char *path = "PATH=";

	if (envar == NULL)
	{
		perror("NULL ARGUMENT");
		return (NULL);
	}
	while (*envar != '\0' && *path != '\0' && *envar == *path)
	{
		envar++;
		path++;
	}
	if (*path != '\0')
	{
		return (NULL);
	}
	return (envar);
}

/**
  * findpath - finds the PATH variable within environmental variable list
  *
  * Return: Pointer to path variable, or NULL on fail
  */
char *findpath()
{
	int i;
	char *pathvar;
	char *findmatch;

	i = 0;
	pathvar = NULL;

	while (environ[i] != NULL)
	{
		findmatch = path_match(environ[i]);
		if (findmatch)
		{
			pathvar = findmatch;
			break;
		}
		else
			i++;
	}
	return (pathvar);
}

