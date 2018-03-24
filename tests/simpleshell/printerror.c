#include "holberton.h"
/**
  * _strlen - finds length of string
  * @str - input string
  *
  * Return: length of string
  */
int _strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}

void printerror(char **arg, static int arc, char *line) {
char *buf;

buf = arc

	write(STDOUT_FILENO, arg[0], _strlen(arg[0]));
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
	write(STDOUT_FILENO, buf, _strlen(buf));
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
	write(STDOUT_FILENO, "command", sizeof(char) * 7);
	write(STDOUT_FILENO, ": not found\n", sizeof(char) * 13);
}
