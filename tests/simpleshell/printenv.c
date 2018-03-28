#include "holberton.h"
/**
* printenviron - prints environment
* @tokens: is our broken string
* Return: 1 if success or 0 if fails
**/
int printenviron(char **tokens)
{
	int i;

	i = 0;

	if (_strcmp(tokens[0], "env") == 0)
	{
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 2);
			i++;
		}
		return (1);
	}
	return (-1);
}
