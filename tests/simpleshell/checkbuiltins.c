#include "holberton.h"
/**
  * checkbuiltins - checks input for builtins
  * @tokens: tokenized command
  * @line: input line
  *
  * Return: -1 if not builtin, 1 if printenv, exit if exit
  */
int checkbuiltins(free_t *stash)
{
	if (__exit(stash) == -1)
	{
		if (printenviron(stash->commands) == -1)
			return (-1);
	}
	return (-1);
}
