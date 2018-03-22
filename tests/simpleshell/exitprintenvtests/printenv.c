#include "holberton.h"

/**
* printenviron - prints environment
* @argv: input variable
* Return 1 if success or 0 if fails
**/
int printenviron(char **argv)
{
	int i = 0;
	extern char **environ;

	if (_strcmp(argv[0], "env") == 0)
	{
		while(environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			i++;
		}
		return (1);
	}
	else
		return (0);
}
