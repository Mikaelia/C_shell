#include "holberton.h"

/**
 * freelist - frees linked list
 * @head: head of linked list
 * Return: freed list
 */

void freelist(tokenlist_t *head)
{
	tokenlist_t *tmp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
