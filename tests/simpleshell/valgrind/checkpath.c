#include "holberton.h"

/**
  * checkpath - checks path for executable
  * @command: input command string
  * Return: NULL if no match found, or executable file if founc
  */
char *checkpath(char *command)
{
	char *executable;
	char *pathvar;
	tokenlist_t *pathlist;
	struct stat st;

	if (command == NULL)
	{
		return (NULL);
	}
	pathvar = findpath();
	if (pathvar == NULL)
	{
		return (NULL);
	}
	pathlist = pathsplitlist(pathvar);
	while (pathlist)
	{
		printf("%s", pathlist->token);
		executable = appendcmd(pathlist, command);
		if (stat(executable, &st) < 0)
		{
			free(executable);
			pathlist = pathlist->next;
		}
		else if (stat(executable, &st) == 0)
		{
			freelist(pathlist);
			return (executable);
		}
	}
	freelist(pathlist);
	return(NULL);
}
