#include "holberton.h"
/**
 * _strcmp - searches env variable strings for PATH name
 * @envar: environmental variable string to compare
 *
 * Return: 1 on match, -1 if no match found
 */
char *_strcmp(char *envar)
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
  * findpath - finds the path variable in environmental variable array
  *
  * Return: Pointer to path variable string, or NULL pointer on fail
  */
char *findpath()
{
	char *pathvar;
	int i;
	char *findmatch;

	pathvar = NULL;
	i = 0;

	while (environ[i] != NULL)
	{
		findmatch = _strcmp(environ[i]);
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
