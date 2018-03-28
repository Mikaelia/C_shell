#include "holberton.h"
/**
  * checkbuiltins - checks input for builtins
  * @tokens: tokenized command
  * @line: input line
  *
  * Return: -1 if not builtin, 1 if printenv, exit if exit
  */
int checkbuiltins(char **tokens)
{
	if (__exit(tokens) == -1)
	{
		if (printenviron(tokens) == -1)
			return (-1);
	}
	return (-1);
}
