#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @stash: struct of pointers
  * @av: argument variables passed from stdin
  * @count: count of executed commands
  *
  * Return: 0
 */
void launch(char **av, free_t *stash, int count)
{
	pid_t child_pid;

	if (checkbuiltins(stash) == -1)
	{
		checkpath(stash);
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Child failed");
		}
		if (child_pid == 0)
		{
			if (execve(stash->commands[0], stash->commands, NULL) == -1)
			{
				if (execve(stash->executable, stash->commands, NULL) == -1)
				{
					printerror(av, count, stash->input);
					free(stash->input);
					_exit(2);
				}
			}
		}
		else
		{
			wait(NULL);
		}
	}
}
