#include "holberton.h"
/**
  * tokenize - parses input line into tokens
  * @str: str is our string we will be separating into tokens
  *
  * Return: Array of each word of string
  */
char **tokenize(char *str)
{
	char **tokens;
	char *token;
	int i;
	const char *deliminator  = " \t\r\n\a";
	int bufsize = 20;
	int newbuf;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		return (NULL);
	}

	token = strtok(str, deliminator);
	if (!token)
	{
		return (NULL);
	}
	i = 0;
	while (token != NULL)
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
