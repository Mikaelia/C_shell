#include "holberton.h"
/**
  * checkbuiltins - checks input against builtins
  * @tokens: token to check
  * @line: string that is being checked
  * Return: -1 if not builtin, 1 if printenv, exit if exit
  */
int checkbuiltins(char **tokens, char *line)
{
	if (__exit(tokens, line) == -1)
	{
		if (printenviron(tokens) == -1)
			return (-1);
	}
	return (-1);
}
