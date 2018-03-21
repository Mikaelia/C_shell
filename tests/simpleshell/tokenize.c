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
		free(ptr);
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
		free(ptr);
	}
	if (resized < original)
	{
		for (i = 0; i < resized; i++)
			newbuf[i] = tmp[i];
		free(ptr);
	}
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
