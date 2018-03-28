#include "holberton.h"
/**
 * sig_handler - handles ctrl + c signal interruption
 * @sig_handler: signal recieved - unused
 * Return: void
 */
void sig_handler(int sigint)
{
	if (sigint == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
/**
  * looper - continuous shell loop
  * @av: argument variables
  * Return: nothing
  */
void looper(char **av)
{
	char *input;
	static int count = 1;

	free_t stash = {NULL, NULL, NULL, NULL, NULL};
	input = NULL;

	signal(SIGINT, sig_handler);

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	while (_prompt(&input, &stash))
	{
		if (stash.input[0] == '\n')
		{
			write(STDOUT_FILENO, "$ ", 2);
			free(stash.input);
			continue;
		}

		if (!(tokenize(&stash)))
		{
			perror("tokenize fail");
			free(stash.input);
			continue;
		}

		launch(av, &stash, count);

		count++;
		free2pointer(stash.commands);
		free(stash.pathvar);
		free(stash.input);

		write(STDOUT_FILENO, "$ ", 2);
	}
}
