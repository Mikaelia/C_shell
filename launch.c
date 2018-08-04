#include "holberton.h"
/**
  * appendcmd - creates new buffer to hold PATH value + user input
  * @command: first argument passed through stdin
  * @h: linked list head of PATH variables
  * Return: pointer to newly allocated space with combined data
  */
char *appendcmd(const tokenlist_t *h, char *command)
{
	char *token;
	char *new;
	int sum, i, j;

	sum = 0;
	i = 0;
	j = 0;
	token = h->token;

	if (h == NULL)
		return (NULL);
	if (command == NULL)
		return (NULL);

	sum += _strlen(token);
	sum += _strlen(command);

	new = malloc((sizeof(char) * sum) + 2);
	if (new == NULL)
	{
		return (NULL);
	}
	while (token[i] != '\0')
	{
		new[i] = token[i];
		i++;
	}
	new[i] = '/';
	i++;
	while (command[j] != '\0')
	{
		new[i] = command[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}
/**
  * checkbuiltins - checks if input arg is a builtin
  * @stash: variable storage struct
  * Return: -1 if not builtin, 1 if 'printenv', exit if 'exit'
  */
int checkbuiltins(free_t *stash)
{
	if (__exit(stash) == -1)
	{
		if (printenviron(stash->commands) == -1)
			return (-1);
	}
	return (-1);
}

/**
  * checkpath - checks PATH for executable
  * @stash: variable storage struct
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

	//convert PATH variable contents to linked list
	pathlist = path_to_list(stash->pathvar);
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

/**
  * launch - forks process and executes commands
  * @stash: struct of pointers
  * @av: argument variables passed from stdin
  * @count: count of executed commands
  *
  * Return: 0
 */
void launch(char **args, free_t *stash, int count)
{
	pid_t child_pid;

	if (checkbuiltins(stash) == -1)
	{
		if (checkpath(stash) == NULL)
		{
			stash->executable = NULL;
		}
		child_pid = fork();
		if (child_pid == -1)
		{
			perror("Child failed");
		}
		if (child_pid == 0)
		{
			if (execve(stash->commands[0], stash->commands, NULL) == -1)
			{
				if (stash->executable != NULL)
				{
					execve(stash->executable, stash->commands, NULL);
				}
				printerror(args, count, stash->input);
				free(stash->input);
				_exit(2);
			}
		}
		else
		{
			wait(NULL);
		}
	}
}
