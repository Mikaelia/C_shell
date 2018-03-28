#include "holberton.h"
/**
 * sig_handler - handles ctrl + c signal interruption
 * @sig_handler: signal recieved - unused
 * Return: void
 */
void sig_handler(int sig_handler)
{
	(void) sig_handler;

	if (flag == 0)
		write(STDOUT_FILENO, "\n", 1);
	else
		write(STDOUT_FILENO, "\n$ ", 3);
}
/**
  * looper - continuous shell loop
  *
  *
  *
  *
  */
void looper(char **av)
{
	char *input;
	unsigned int interactive = 0;
	static int count = 1;

	free_t stash = {NULL, NULL, NULL, NULL, NULL};

	signal(SIGINT, sig_handler);

	if (!isatty(STDIN_FILENO))
		interactive = 1;
	if (interactive == 0)
		write(STDOUT_FILENO, "$ ", 2);
	flag = 0;
	input = NULL;

	while (_prompt(&input, &stash))
	{
		flag = 1;
		printf("%s", stash.input);

		if (stash.input[0] == '\n')
		{
			write(STDOUT_FILENO, "$ ", 2);
			continue;
		}

		if(!(tokenize(&stash)))
		{
			perror("tokenize fail");
			free(stash.input);
			continue;
		}

		launch(av, &stash, count);

		count++;
		free2pointer(stash.commands);
		free(stash.pathvar);


		flag = 0;
		if (interactive == 0)
			write(STDOUT_FILENO, "$ ", 2);
	}
	if (interactive == 0)
		write(STDOUT_FILENO, "\n", 1);
	free(stash.input);
}
