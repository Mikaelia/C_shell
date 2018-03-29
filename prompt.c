#include "holberton.h"
/**
  * _prompt - reads line for prompt
  * @line: pointer to inputed commands
  * @stash: structure of pointers
  * Return: buffer containing command line arguments
  */
int _prompt(char **line, free_t *stash)
{
	size_t bufsize = 0;

	if (getline(line, &bufsize, stdin) == -1)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(*line);
		exit(0);
	}
	stash->input = *line;
	return (1);
}
