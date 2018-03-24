#include "holberton.h"
/**
  * launch - forks process and executes commands
  * @argv: arg passed from stdin
  *
  * Return: 0
 */
int launch(char **argv)
{
	pid_t child_pid;
	char *executable;

	executable = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		printf("Error:");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			executable = checkpath(argv[0]); /*return NULL on fail*/
			if (executable == NULL)
			{
				printf("NO PATH MATCH");
				exit(0);
			}
			if (execve(executable, argv, NULL) == -1)
			{
				printf("EXECUTE FAIL");
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
