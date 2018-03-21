#include "holberton.h"
/**
  * pathsplit - splits path into tokens
  * @path: path is an enviromental variable
  *
  * Return: Array of each word of string
  */
char **pathsplit(char *path)
{
	char **patharray;
	char *pathtoken;
	const char *deliminator  = ":";
	int i;
	int bufsize;
	int newbuf;

	bufsize = 1;
	if (!path)
	{
		perror("Null input string");
		return (NULL);
	}
	while (i = 0, path[i] != '\0', i++)
	{
		if (path[i] == deliminator[0])
			bufsize++;

	pathtoken = strtok(path, deliminator);
	if (!pathtoken)
	{
		return (NULL);
	}
	while (pathtoken != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			newbuf = bufsize + 5;
			tokens = _realloc(tokens, bufsize * sizeof(char*),
					  newbuf * sizeof(char*));
			if (!tokens)
				return (NULL);
		}
		token = strtok(NULL, deliminator);
	}
	tokens[i] = '\0';
	return (tokens);
}
