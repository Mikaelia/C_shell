#include "holberton.h"
/**
 * path_match - searches env variable for PATH, and returns subsequent file path
 * @envar: environmental variable to compare
 *
 * Return: 1 on match, -1 if no match found
 */
char *path_match(char *envar)
{
	char *to_match = "PATH=";

	if (envar == NULL)
	{
		perror("NULL ARGUMENT");
		return (NULL);
	}
	while (*envar != '\0' && *to_match != '\0' && *envar == *to_match)
	{
		envar++;
		to_match++;
	}
	if (*to_match != '\0')
	{
		return (NULL);
	}
	// return string following 'PATH='
	return (envar);
}

/**
  * findpath - finds the PATH variable within environmental variable list
  *
  * Return: Pointer to executable path, or NULL on fail
  */
char *findpath()
{
	int i;
	char *path;
	char *findmatch;

	i = 0;
	pathvar = NULL;

	while (environ[i] != NULL)
	{
		// cycles through env variables
		findmatch = path_match(environ[i]);
		if (findmatch)
		{
			path = findmatch;
			break;
		}
		else
			i++;
	}
	return (path);
}

