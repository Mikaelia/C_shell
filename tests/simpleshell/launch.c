#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @argv: arg passed from stdin
  *
  * Return: 0
 */
int launch(char **av, free_t stash, int count)
{
	pid_t child_pid;
	char *executable;

	executable = NULL;

	if (checkbuiltins(stash.commands, stash.input) == -1)
	{
		executable = checkpath(stash);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Child failed");
			exit(0);
		}
		if (child_pid == 0)
		{
			if (execve(stash.commands[0], stash.commands, NULL) == -1)
			{
				if (execve(executable, stash.commands, NULL) == -1)
				{
					printerror(av, count, line);
					_exit(0);
				}
			}

		}
		else
		{
			wait(NULL);
		}
	}
	return (1);
}
