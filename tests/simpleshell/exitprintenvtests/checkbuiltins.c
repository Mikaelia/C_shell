#include "holberton.h"
/**
  * checkbuiltins - checks input against builtins
  * @tokens: token to check
  *
  * Return: -1 if not builtin, 1 if printenv, exit if exit
  */
int checkbuiltin(char **tokens)
{
	if (_exit(tokens) == -1)
		return (-1);
}
