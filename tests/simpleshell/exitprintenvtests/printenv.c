#include "holberton.h"
/**
 * _strcmp_env - compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: s1 - s2 or 0
 */
int _strcmp_env(char *s1, char *s2)
{
	while (*s1 != '\0' &&  *s2 != '\0')
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}

/**
* printenviron - prints environment
* @argv: input variable
* Return 1 if success or 0 if fails
**/
int printenviron(**tokens)
{
	int i = 0;
	int j = 0;

	if (_strcmp_env(tokens[0], env) == 0)
	{
		while(environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 1);
			i++;
		}
		exit(0);
	}
	return (-1);
}
