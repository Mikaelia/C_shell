#include <stdio.h>
#include <unistd.h>
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

void printerror(char **arg, char *arc, char *line) {
char *buf;

	write(STDOUT_FILENO, arg[0], _strlen(arg[0]));
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
	write(STDOUT_FILENO, "4", sizeof(char) * 2);
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
	write(STDOUT_FILENO, "command", sizeof(char) * 7);
	write(STDOUT_FILENO, ": not found\n", sizeof(char) * 13);
}
