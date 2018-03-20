#include "holberton.h"
void freelist(tokenlist_t **head)
{
	tokenlist_t *ptr;

	if (head == NULL)
		return;

	while (*head != NULL)
	{
		ptr = *head;
		*head = (*head)->next;
		free(ptr);
	}
	head = NULL;
}
