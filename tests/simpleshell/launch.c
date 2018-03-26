#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @argv: arg passed from stdin
  *
  * Return: 0
 */
int launch(char **args)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		exit(0);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			exit(0);
	}
	else
	{
		wait(&status);
	}
	return (1);
}
