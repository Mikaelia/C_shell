#include "holberton.h"
/**
  * _prompt - reads line for prompt
  *
  * Return: buffer containing command line arguments
  */
char *_prompt()
{
	char *line = NULL;
	int s;
	size_t bufsize = 0;

	printf("$ ");
	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
