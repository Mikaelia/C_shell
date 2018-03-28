#include "holberton.h"

/**
  * checkpath - checks path for executable
  * @command: input command string
  * Return: NULL if no match found, or executable file if founc
  */
char *checkpath(free_t *stash)
{
	tokenlist_t *pathlist;
	struct stat st;

	if (stash->commands[0] == NULL)
	{
		return (NULL);
	}

	stash->pathvar = _strdup(findpath());
	if (stash->pathvar == NULL)
	{
		return (NULL);
	}
	pathlist = pathsplitlist(stash->pathvar);
	while (pathlist)
	{
		stash->executable = _strdup(appendcmd(pathlist, stash->commands[0]));
		if (stat(stash->executable, &st) < 0)
		{
			free(stash->executable);
			pathlist = pathlist->next;
		}
		else
			break;
	}
	freelist(pathlist);
	return (NULL);
}
