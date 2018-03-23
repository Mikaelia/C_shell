#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @argv: arg passed from stdin
  *
  * Return: 0
 */
int launch(char **tokens)
{
	pid_t child_pid;
	char *executable;
	int i;

	executable = NULL;
	i = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(tokens[0], argv, NULL) == -1)
		{
			executable = checkpath(tokens[0]); /*return NULL on fail*/
			if (execve(executable, argv, NULL) == -1)
			{
				printerror;
				exit(0);
			}
		}
	}
	else
	{
		do {
			child_pid = wait(NULL);
			i++;
		} while (tokens[i] != NULL);
	}
	return (1);
}
