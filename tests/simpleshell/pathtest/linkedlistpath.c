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
  * pathsplit - splits path into tokens
  *
  * Return: Array of each word of string
  */
tokenlist_t *pathsplitlist(char *path)
{
	char *pathtoken;
	const char *deliminator  = ":";
	int i, j;
	int bufsize;
	tokenlist_t *pathhead;

	bufsize = 2;
	i = 0;
	j = 0;
	pathhead = NULL;

	if (!path)
	{
		perror("Null input string");
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
		printf("TOKEN FAIL");
		return (NULL);
	}
	while (pathtoken != NULL)
	{
		tokentolist(&pathhead, pathtoken);
		pathtoken = strtok(NULL, deliminator);
		j++;
	}
	return (pathhead);
}
