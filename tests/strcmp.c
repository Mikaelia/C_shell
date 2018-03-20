#include "holberton.h"
/**
 * _strcmp - compares two strings
 *
 * @s1: first string to compare
 * @s2: second string to compare
 *
 *
 * Return: 1 on match
 *
 */
int _strcmp(char *envar)
{
	char *var = "PATH=";

	if (envar == NULL)
	{
		perror("NULL ARGUMENT");
		exit (2);
	}
	while (*envar != '\0' && *var != '\0' && *envar == *var)
	{
		envar++;
		var++;
	}
	if (*var != '\0')
	{
		return (-1);
	}
	return (1);
}
