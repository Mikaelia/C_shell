#include "holberton.h"

/**
 * _strcmp - compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: s1 - s2 or 0
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
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

void _atoi(char *s)
{
	int sum = 0;

	if (s == NULL)
		return (-1);

	while(*s != '\0')
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
 * escape - built in exit function
 * @argv: argument variable
 */

void escape(char **argv)
{
	int i; /* converting string to a int */

	if (_strcmp(argv[0], "exit") == 0)
	{
		i = _atoi(argv[1]);
		if (i > 0)
		{
			exit(i);
		}

		else
			perror("default exit")
			exit(100);
	}
}
