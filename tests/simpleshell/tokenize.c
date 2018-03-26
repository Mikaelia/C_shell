#include "holberton.h"
/**
 * _realloc - function that reallocates  memory space
 * @ptr: input string
 * @original: original size of  memory space
 * @resized: resized  memory space
 * Return: NULL or string
 */
void *_realloc(void *ptr, unsigned int original, unsigned int resized)
{
	char *newbuf;
	void *vptr;
	char *tmp;
	unsigned int i;

	if (original == resized)
		return (ptr);
	if (resized == 0 && ptr != NULL)
	{
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(resized));
	}
	tmp = ptr;
	newbuf = malloc(resized);
	if (newbuf == NULL)
		return (NULL);

	if (resized > original)
	{
		for (i = 0; i < original; i++)
			newbuf[i] = tmp[i];
	}
	free(ptr);
	vptr = newbuf;
	return (vptr);
}
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
	int new;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
	{
		return (NULL);
	}

	token = strtok(str, deliminator);
	if (!token)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(tokens);
		exit(0);
	}
	i = 0;
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			new = bufsize + 5;
			tokens = _realloc(tokens, bufsize * sizeof(char *), new * sizeof(char *));
			if (!tokens)
				return (NULL);
		}
		token = strtok(NULL, deliminator);
	}
	tokens[i] = '\0';
	return (tokens);
}
