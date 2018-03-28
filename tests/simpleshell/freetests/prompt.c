#include "holberton.h"
/**
  * _prompt - reads line for prompt
  *
  * Return: buffer containing command line arguments
  */
char *_prompt(void)
{
	char *line = NULL;
	int s;
	size_t bufsize = 0;

	printf("$ ");
	s = getline(&line, &bufsize, stdin); /*stores address of buffer w args*/
	if (s == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
