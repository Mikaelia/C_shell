#include "holberton.h"
/**
 * __exit - built in exit function
 * @stash: program variable structure
 * Return: -1
 */
int __exit(free_t *stash)
{
	int i;

	if (_strcmp(stash->commands[0], "exit") == 0)
	{
		i = _atoi(stash->commands[1]);
		if (i > 0)
		{
			free2pointer(stash->commands);
			free(stash->input);
			exit(i);
		}
		else
		{
			free2pointer(stash->commands);
			free(stash->input);
			exit(0);
		}
	}
	return (-1);
}

/**
* printenviron - prints environment
* @tokens: pointer to tokens
* Return: 1 if success or 0 if fails
**/
int printenviron(char **tokens)
{
	int i;

	i = 0;

	if (_strcmp(tokens[0], "env") == 0)
	{
		while (environ[i] != NULL)
		{
			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
			write(STDOUT_FILENO, "\n", 2);
			i++;
		}
		return (1);
	}
	return (-1);
}
