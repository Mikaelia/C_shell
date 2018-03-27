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
void tokenize(free_t *stash)
{
	int i;
	const char *deliminator  = " \t\r\n\a";
	int bufsize = 20;
	int newsize;

	stash->commands = malloc(sizeof(char *) * bufsize);

	stash->token = _strdup(strtok(stash->input, deliminator));
	if (!stash->token)
	{
		write(STDOUT_FILENO, "\n", 1);
		free(stash->commands);
		exit(2);
	}
	i = 0;
	while (stash->token != NULL)
	{
		stash->commands[i] = stash->token;
		i++;
		if (i >= bufsize)
		{
			newsize = bufsize + 5;
			stash->commands = _realloc(stash->commands, bufsize * sizeof(char *), newsize* sizeof(char *));
			if (!stash->commands)
			{
				perror("REALLOC FAIL");
				exit(2);
			}
		}
		stash->token = _strdup(strtok(NULL, deliminator));
	}
	stash->commands[i] = '\0';
}
