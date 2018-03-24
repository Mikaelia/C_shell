#include "holberton.h"
/**
  * _len - finds length of string
  * @str - input string
  *
  * Return: length of string
  */
int _len(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}
/**
  * printerror - prints error message
  * @arg: main argument list
  * @arc: number of arguments executed
  * @line: input from prompt
  *
  * Return: void
  */
void printerror(char **arg, int arc, char *line)
{

	write(STDOUT_FILENO, arg[0], _len(arg[0]));
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
	write(STDOUT_FILENO, &arc, sizeof(char) * 5);
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
	write(STDOUT_FILENO, line, _len(line));
	write(STDOUT_FILENO, ": not found\n", sizeof(char) * 13);
}
