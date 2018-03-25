#include "holberton.h"
/**
* printenviron - prints environment
* @argv: input variable
* Return 1 if success or 0 if fails
**/
int printenviron(char **tokens)
{
	int i = 0;

	if (_strcmp(tokens[0], "env") == 0)
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
