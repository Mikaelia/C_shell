#include "holberton.h"
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
		return(-1);

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
 * __exit - built in exit function
 * @tokens: arg list
 */
int __exit(char **tokens, char *line)
{
	int i;

	if (_strcmp(tokens[0], "exit") == 0)
	{
		i = _atoi(tokens[1]);
		if (i > 0)
		{
			free2pointer(tokens);
			free(line);
			exit(i);
		}
		else
		{
			free(line);
			free2pointer(tokens);
			exit(0);
		}
	}
	return (-1);
}
