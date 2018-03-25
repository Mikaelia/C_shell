#include "holberton.h"
/**
  * _strlen - finds length of string
  * @string: input string
  * Return: int length, or 0 on error/empty
  */
int _strlen(char *string)
{
	int count;

	if (string == NULL)
	{
		return (0);
	}

	count = 0;
	while (string != NULL)
	{
		count++;
		string++;
	}
	count++;
	return (count);
}
/**
  * appendcmd - creates new buf to hold nodeval + user input
  * @command: first argument passed to input stream
  * @h: linked list head
  * Return: pointer to newly allocated space w data
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

	sum += strlen(token);
	sum += strlen(command);

	new = malloc(sizeof(char) * sum + 2);
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
