#include "holberton.h"
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
