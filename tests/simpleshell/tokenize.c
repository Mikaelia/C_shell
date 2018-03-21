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
		perror("TOKEN FAIL");
		return (NULL);
	}
	while (token != NULL)
	{
		{
			newbuf = bufsize + 5;
<<<<<<< HEAD
			tokens = _realloc(tokens, bufsize * sizeof(char*),
					  newbuf * sizeof(char*));
=======
			tokens = _realloc(tokens, bufsize * sizeof(char*), newbuf * sizeof(char*));
>>>>>>> 69f9a6007a3f58427b181c249b1a7e042c79cada
			if (!tokens)
				return (NULL);
		}
	}
	tokens[i] = '\0';
	return (tokens);
}
