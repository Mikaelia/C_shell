#include "holberton.h"
/**
  * appendcmd - creates new buf to hold nodeval + user input
  * @command: first argument passed to input stream
  * @head: linked list head
  *
  * Return: pointer to newly allocated space w data
  */
char *appendcmd(const tokenlist_t *head, char *command)
{

	while (head != NULL)
	{
		char *token;
		char *new;
		int sum, i, j;

		sum = 0;
		i = 0;
		j = 0;
		token = h->token;

		sum += strlen(token);
		sum += strlen(command);

		new = malloc(sizeof(char) * sum);
		if (new == NULL)
		{
			return (NULL)
		}
		while (token[i] != '\0')
		{
			new[i] = token[i];
			i++;
		}
		while (command[j] != '\0')
		{
			new[i] = command[j];
			i++;
			j++;
		}
		new[i] = '\0';
		/*STAT HERE*/
		/* if found, return. Else... */

		h = h->next;
	}
	return (new);
}
