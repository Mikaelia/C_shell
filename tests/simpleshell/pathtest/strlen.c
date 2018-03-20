#include "holberton.h"
/**
  * _strlen - finds length of string
  *
  *
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
