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
>>>>>>> a8e1bbb71d75ace8dc2a57869d022dcfbd621524
		if (input == NULL)
		{
			perror("getline fail");
			exit(1);
		}
		tokens = tokenize(input);	/*splits input into tokens*/
		if (!tokens)
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
		free2pointer(tokens);
		free(input);

		flag = 0;
		if (interactive == 0)
			write(STDOUT_FILENO, "$ ", 2);
>>>>>>> a8e1bbb71d75ace8dc2a57869d022dcfbd621524
	} while (status);
	if (interactive == 0)
		write(STDOUT_FILENO, "\n", 1);
}
