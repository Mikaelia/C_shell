#include "holberton.h"
/**
 * _strcmp2 - compares two strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: 0 if match found, 
 */

int _strcmp2(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
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
	if (sum > 255)
		return (-1);
	else
		return (sum);
}
/**
 * escape - built in exit function
 * @argv: argument variable
 */

void escape(char **token)
{
	int i;

	if (_strcmp2(token[0], "exit") == 0)
	{
		i = _atoi(token[1]);
		if (i >= 0)
		{
			exit(i);
		}
		else
			exit(100);
	}
	else
		exit()
}
