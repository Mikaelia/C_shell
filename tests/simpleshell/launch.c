#include "holberton.h"
/**
  * launch - forks process and executes commands
  *
  *
  *
  * Return: 0
 */
int launch(char **argv)
{
    	pid_t child_pid;
	char* executable;
	int i = 0;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
	{
		escape(argv); /* exit */
		if (execve(argv[0], argv, NULL) == -1)
		{
			executable = checkpath(); /*return NULL on fail*/
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
		escape(argv); /* exit */
		do
		{
			child_pid = wait(NULL);
			i++;
		}while (argv[i] != NULL);
	}
	return (1);
}
