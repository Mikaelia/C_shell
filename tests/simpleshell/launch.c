#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @argv: arg passed from stdin
  *
  * Return: 0
 */
int launch(char **av, char **tokens, char *line, int count)
{
	pid_t child_pid;
	char *executable;

	executable = NULL;

	if (checkbuiltins(tokens, line) == -1)
	{
		executable = checkpath(tokens[0]); /*return Null on fail */
		child_pid = fork();
		if (child_pid == -1)
		{
			exit(0);
		}
		if (child_pid == 0)
		{
			if (execve(tokens[0], tokens, NULL) == -1)
			{
				if (execve(executable, tokens, NULL) == -1)
				{
					printerror(av, count, line);
					exit(0);
				}
			}

		}
		else
		{
			child_pid = wait(NULL);
		}
	}
	return (1);
}
