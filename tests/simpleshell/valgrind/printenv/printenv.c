#include "holberton.h"
/**
  *
  *
  */
int len(char *token)
{
	int i;
	i = 0;

	while (token[i] != 0)
	{
		i++;
	}
	i++;
	return (i);
}
void main(void)
{
	int i;

	i = 0;
	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], len(environ[i]));
		write(STDOUT_FILENO, "\n", 2);
		i++;
	}
}
