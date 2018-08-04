#include "holberton.h"
/**
  * _prompt - reads and stores arguments to stdin
  * @line: reference to input arguments
  * @stash: variable storage struct
  * Return: stores string of arguments on success, exit on fail
  */
int _prompt(char **line, free_t *stash)
{
	size_t bufsize = 0;

	if (getline(line, &bufsize, stdin) == -1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(*line);
		exit(0);
	}
	stash->input = *line;
	return (1);
}

/**
 * sig_handler - handles keyboard signal interruption
 * @sigint: signal recieved
 * Return: void
 */
void sig_handler(int sigint)
{
	if (sigint == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}

/**
  * shell_loop - shell main program loop
  * @args: argument variables
  * Return: exit on termination of simple shell
  */
void shell_loop(char **args)
{
	char *input;
	static int count = 1;
	unsigned int interactive = 1;

	// struct to hold program variables (see header file)
	free_t stash = {NULL, NULL, NULL, NULL};
	input = NULL;

	signal(SIGINT, sig_handler);

	// check interactive/non-interactive mode
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	else
		interactive = 0;

	// check for and gather user input
	while (_prompt(&input, &stash))
	{
		if (stash.input[0] == '\n')
		{
			write(STDOUT_FILENO, "$ ", 2);
			free(stash.input);
			continue;
		}

		// split user input
		if (!(tokenize(&stash)))
		{
			perror("tokenize fail");
			free(stash.input);
			continue;
		}

		// execute command
		launch(args, &stash, count);

		// free memory
		count++;
		free2pointer(stash.commands);
		free(stash.pathvar);
		free(stash.input);
		free(stash.executable);

		if (interactive != 0)
			write(STDOUT_FILENO, "$ ", 2);
		stash.input = NULL;
	}
	if (interactive != 0)
		write(STDOUT_FILENO, "\n", 1);
	free(stash.input);
}

/**
  * main - main function for simple shell
  * @argc: argument count
  * @argv: pointer to argument variable
  * Return: 0 on exit or fail
  */
int main(__attribute__((unused))int argc, char **argv)
{
	shell_loop(argv);
	return (0);
}
