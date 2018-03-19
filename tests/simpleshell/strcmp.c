#include "holberton.h"
/**
 * _strcmp - searches env variable strings for PATH variable
 * @envar: environmental variable string to compare
 *
 * Return: 1 on match, -1 if no match found
 */
int _strcmp(char *envar)
{
	char *path = "PATH=";

	if (envar == NULL)
	{
		perror("NULL ARGUMENT");
		exit (2);
	}
	while (*envar != '\0' && *path != '\0' && *envar == *path)
	{
		envar++;
		path++;
	}
	if (*path != '\0')
	{
		return (-1);
	}
	return (1);
}
