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
