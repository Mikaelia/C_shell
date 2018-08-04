#include "holberton.h"
/**
  * token_to_list - adds tokens to linked list
  * @head: head of list
  * @token: string token to add to list
  *
  * Return: pointer to the linked list head, NULL on fail
  */
void token_to_list(tokenlist_t **head, char *token)
{
	tokenlist_t *new;
	tokenlist_t *temp;

	if (head == NULL)
		return;

	new = malloc(sizeof(tokenlist_t));
	if (new == NULL)
		return;

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
}
/**
  * path_to_list - splits path string into tokens, returns linked list
  * @path: path variable string
  *
  * Return: pointer to list head, or NULL on fail
  */
tokenlist_t *path_to_list(char *path)
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
		token_to_list(&path_head, pathtoken);
		pathtoken = strtok(NULL, deliminator);
	}
	return (path_head);
}
