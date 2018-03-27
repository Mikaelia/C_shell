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
	char **tokens;
	int status;
	unsigned int interactive = 0;
	static int count = 1;

	free_t stash = {NULL, NULL, NULL, NULL};

	signal(SIGINT, sig_handler);

	if (!isatty(STDIN_FILENO))
		interactive = 1;
	if (interactive == 0)
		write(STDOUT_FILENO, "$ ", 2);
	flag = 0;
	do {
		flag = 1;
		status = 0;
		input = NULL;
		tokens = NULL;

		_prompt(&input);
		stash.input = input;
		if (stash.input == NULL)
		{
			perror("getline fail");
			exit(1);
		}
		stash.commands = tokenize(stash.input);		/*splits input into tokens*/
		if (!stash.commands)
		{
			perror("tokenize fail");
			exit(1);
		}
		status = launch(av, tokens, input, count);	/*executes tokens*/
		if (status != 1)
		{
			status = -1;
		}
		count++;
		free2pointer(stash.commands);
		free(stash.input);

		flag = 0;
		if (interactive == 0)
			write(STDOUT_FILENO, "$ ", 2);
	} while (status);
	if (interactive == 0)
		write(STDOUT_FILENO, "\n", 1);
	free(stash.input);
}
