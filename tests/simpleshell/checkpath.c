#include "holberton.h"

/**
  * checkpath - checks path for executable
  * @command: input command string
  * Return: NULL if no match found, or executable file if founc
  */
char *checkpath(free_t stash)
{
	char *pathvar;
	tokenlist_t *pathlist;
	struct stat st;

	if (stash.commands[0] == NULL)
	{
		return (NULL);
	}

	pathvar = _strdup(findpath());
	if (pathvar == NULL)
	{
		free(pathvar);
		return (NULL);
	}
	pathlist = pathsplitlist(pathvar);
	if (pathlist == NULL)
		free(pathvar);
	while (pathlist)
	{
		stash.executable = _strdup(appendcmd(pathlist, stash.commands[0]));
		if (stat(stash.executable, &st) < 0)
		{
			free(stash.executable);
			pathlist = pathlist->next;
		}
		else if (stat(stash.executable, &st) == 0)
			return (stash.executable);
	}
	free(stash.executable);
	free(pathvar);
	freelist(pathlist);
	return(NULL);
}
