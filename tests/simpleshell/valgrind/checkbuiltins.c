#include "holberton.h"
/**
  * checkbuiltins - checks input against builtins
  * @tokens: token to check
  *
  * Return: -1 if not builtin, 1 if printenv, exit if exit
  */
int checkbuiltins(char **tokens, char *line)
{
	if (__exit(tokens, line) == -1 || printenviron(tokens) == -1)
		return (-1);
	else
		return (-1);
}
