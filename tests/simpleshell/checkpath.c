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
		printf("No Command");
		return (NULL);
	}

	pathvar = findpath();
	if (pathvar == NULL)
	{
		free(pathvar);
		return (NULL);
	}
	pathlist = pathsplitlist(pathvar);
	while (pathlist)
	{
		executable = appendcmd(pathlist, command);
		if (stat(executable, &st) < 0)
		{
			free(executable);
			pathlist = pathlist->next;
		}
		else if (stat(executable, &st) == 0)
			return (executable);
	}
	freelist(pathlist);
	return(NULL);
}
