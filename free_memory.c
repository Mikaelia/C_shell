#include "holberton.h"
/**
  * freelist - frees a linked list
  * @head: head of linked list
  *
  * Return: void
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
		tmp = NULL;
	}
	free(head);
}

/**
  * free2pointer - frees a double pointer
  * @tokens: pointer to tokens
  * Return: void
  */
void free2pointer(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		free(tokens[i]);
	}
	free(tokens);
}
