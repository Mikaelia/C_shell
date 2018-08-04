#include "holberton.h"
/**
  * launch - forks process and executes program in 5 children
  *
  *
  *
  * Return: 0
 */
int launch(char **argv)
{
    	pid_t child_pid;
	int i = 0;

	do
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Error:");
		 }
		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("FAIL");
			}
			exit(0);
		}
		else
		{
			child_pid = wait(NULL);
		}
		i++;
	} while (argv != NULL);

	return (1);
}
