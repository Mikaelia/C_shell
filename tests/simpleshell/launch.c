#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @argv: arg passed from stdin
  *
  * Return: 0
 */
int launch(char **av, char **tokens, char *line)
{
	pid_t child_pid;
	char *executable;
	static int count;

	executable = NULL;
	count = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
		{
			count++;
			executable = checkpath(tokens[0]); /*return NULL on fail*/
			if (execve(executable, tokens, NULL) == -1)
			{
				printf("%i", count);
				printerror(av, count, line);
				exit(0);
			}
		}
	}
	else
	{
		child_pid = wait(NULL);
	}
	return (1);
}
