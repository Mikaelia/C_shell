#include "holberton.h"

/**
 * _strcmp_env - compares two strings
 *
 * @s1: string 1
 * @s2: string 2
 *
 * Return: s1 - s2 or 0
 */

int _strcmp_env(char *s1, char *s2)
{
	while (*s1 != '\0' || *s2 != '\0')
	{
		if (*s1 != *s2)
			return (-1);
		s1++;
		s2++;
	}
	if (*s1  == '\0' && *s2 == '\0')
		return (0);
	else
		return (-1);
}

/**
* printenviron - prints environment
* @argv: input variable
* Return 1 if success or 0 if fails
**/
int slen(char *s)
{
	int i = 0;

	while (s[i])
		i++;

	return (i);

}
int printenviron(char **argv)
{

	char env[] = "env";
	int i = 0;
	int j = 0;
	int len = slen(environ[i]);

			  printf("%d\n", len);

	if (_strcmp_env(argv[0], env) == 0)
	{
		while(environ[i] != NULL)
		{
			while ( environ[i][j] != '\0')
//			write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
//			write(STDOUT_FILENO, "\n", 1);
//			i++;
			printf("%s\n", environ[i++]);
		}
		j++;
		return (1);
	}
	else
	return (0);
}
