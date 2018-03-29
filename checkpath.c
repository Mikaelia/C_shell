#include "holberton.h"

/**
  * checkpath - checks path for executable
  * @stash: pointer to main program values
  * Return: NULL if no match found, or executable file if found
  */
tokenlist_t *checkpath(free_t *stash)
{
	tokenlist_t *pathlist, *head;
	struct stat st;
	char *temp;

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
	head = pathlist;
	while (pathlist)
	{
		temp = appendcmd(pathlist, stash->commands[0]);
		stash->executable = _strdup(temp);
		free(temp);
		if (stash->executable == NULL)
		{
			freelist(head);
			return (NULL);
		}
		if (stat(stash->executable, &st) < 0)
		{
			free(stash->executable);
			pathlist = pathlist->next;
		}
		else
			break;
	}
	freelist(head);
	return (pathlist);
}
