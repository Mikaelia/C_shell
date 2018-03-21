#include "holberton.h"
/**
 * _strcmp - searches env variable strings for PATH name
 * @envar: environmental variable string to compare
 *
 * Return: 1 on match, -1 if no match found
 */
char* _strcmp(char *envar)
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
