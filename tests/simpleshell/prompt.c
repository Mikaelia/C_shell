#include "holberton.h"
/**
  * _prompt - reads line for prompt
  *
  * Return: buffer containing command line arguments
  */
int _prompt(char **line)
{
	int s;
	size_t bufsize = 0;
	s = getline(line, &bufsize, stdin);
	if (s == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		exit(2);
	}
	return (s);
}
