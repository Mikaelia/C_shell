#include "holberton.h"
/**
  * checkbuiltins - checks input against builtins
  * @tokens: token to check
  *
  * Return: -1 if not builtin, 1 if printenv, exit if exit
  */
int checkbuiltins(char **tokens)
{
	int num;

	num = __exit(tokens);
	printf("THIS IS MY EXIT BUILTIN%i", num);
	return (-1);
}
