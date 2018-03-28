#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @argv: arg passed from stdin
  *
  * Return: 0
 */
<<<<<<< HEAD
int launch(char **argv, char **tokens)
{
	pid_t child_pid;
	char *executable;
	static int comcount;

	executable = NULL;
	comcount = 0;

	child_pid = fork();
	comcount++;
	if (child_pid == -1)
	{
		printf("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(tokens[0], tokens, NULL) == -1)
=======
void launch(char **av, free_t *stash, int count)
{
	pid_t child_pid;

	if (checkbuiltins(stash->commands, stash->input) == -1)
	{
		checkpath(stash);

		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Child failed");
		}
		if (child_pid == 0)
>>>>>>> origin/reset
		{
			if (execve(stash->commands[0], stash->commands, NULL) == -1)
			{
<<<<<<< HEAD
				printerror(argv, comcount, tokens);
				exit(0);
=======
				if (execve(stash->executable, stash->commands, NULL) == -1)
				{
					perror("EXECUTE ERROR");
					printerror(av, count, stash->input);
					_exit(2);
				}
>>>>>>> origin/reset
			}

		}
		else
		{
			wait (NULL);
		}
	}
<<<<<<< HEAD
	else
	{
		child_pid = wait(NULL);
	}
	printf("%i", comcount);
	return (1);
=======
	return;
>>>>>>> origin/reset
}
