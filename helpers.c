#include "holberton.h"
/**
  * *_strdup - returns duplicate of string str
  * @str: string to duplicate
  *
  * Return: pointer to newly allocated space in memory
  */
char *_strdup(char *str)
{
	char *s;
	int i;
	int j;

	i = 0;
	j = 0;

	if (str == NULL)
		return (NULL);

	while (str[i] != '\0')
	{
		i++;
	}
	i++;
	s = malloc(i * sizeof(char));
	if (s == NULL)
		return (NULL);
	while (j <  i)
	{
		s[j] = str[j];
		j++;
	}
	return (s);
}
/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if match found, else -1
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	return (0);
}
/**
 * _atoi - converts a char to an int
 * @s: input string
 * Return: sum or -1
 */
int _atoi(char *s)
{
	int sum = 0;

	if (s == NULL)
		return (-1);

	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			sum *= 10;
			sum += (*s - '0');
			s++;
		}
		else
			return (-1);
	}
	return (sum);
}

/**
  * _strlen - finds length of string
  * @string: input string
  * Return: int length, or 0 on error/empty
  */
int _strlen(char *string)
{
	int i;

	if (string == NULL)
	{
		return (0);
	}
	i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	i++;
	return (i);
}
