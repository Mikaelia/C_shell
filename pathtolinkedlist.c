#include "holberton.h"
/**
  * tokentolist - adds tokens to linked list
  * @head: head of list
  * @token: string token to add to list
  *
  * Return: pointer to the linked list head, NULL on fail
  */
tokenlist_t *tokentolist(tokenlist_t **head, char *token)
{
	tokenlist_t *new;
	tokenlist_t *temp;

	if (head == NULL)
		return (NULL);

	new = malloc(sizeof(tokenlist_t));
	if (new == NULL)
		return (NULL);

	if (*head == NULL)
		*head = new;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	new->token = token;
	new->next = NULL;
	return (new);
}
/**
  * pathsplitlist - splits path string into tokens, returns linked list
  * @path: path variable string
  *
  * Return: pointer to list head, or NULL on fail
  */
tokenlist_t *pathsplitlist(char *path)
{
	char *pathtoken;
	const char *deliminator  = ":";
	int i;
	int bufsize;
	tokenlist_t *path_head;

	bufsize = 2; /*accounts for null*/
	i = 0;
	path_head = NULL;

	if (!path)
	{
		perror("NULL PATH STRING");
		return (NULL);
	}
	while (path[i] != '\0')
	{
		if (path[i] == deliminator[0])
			bufsize++;
		i++;
	}
	pathtoken = strtok(path, deliminator);
	if (!pathtoken)
	{
		perror("TOKEN FAIL");
		return (NULL);
	}
	while (pathtoken != NULL)
	{
		tokentolist(&path_head, pathtoken);
		pathtoken = strtok(NULL, deliminator);
	}
	return (path_head);
}
