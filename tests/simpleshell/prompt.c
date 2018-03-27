#include "holberton.h"
/**
  * _prompt - reads line for prompt
  * @line: pointer to line
  * Return: buffer containing command line arguments
  */
int _prompt(char **line)
{
	int s;
	size_t bufsize = 0;
	s = getline(line, &bufsize, stdin); /*stores address of buffer w args*/
	if (s == -1)
	{
		free(line);
		return (0);
	}
	return (s);
}
