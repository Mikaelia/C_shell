#include "holberton.h"
/**
  * parse - parse string into tokens
  * @str: input string
  *
  * Return: array of strings
  */
char **parse(char *str)
{
	char **parsedarray;
	const char *deliminator  = ": ";
	char *token;
	int i, j;
	int bufsize;
	int flag;

	bufsize = 1;
	i = 0;
	flag = 1;

	if (!str)
	{
		printf("NULL PATH STRING");
		return (NULL);
	}
	for(i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; deliminator[j] != '\0'; j++)
		{
			if (str[i] == deliminator[j] && flag == 1)
			{
				bufsize++;
				flag = 0;
				break;
			}
		}
		if (str[++i] != deliminator[j])
			flag = 1;
	}
	printf("%i", bufsize);
	parsedarray = malloc(sizeof(char*) * bufsize + 1);
	if (parsedarray == NULL)
		return (NULL);
	i = 0;
	token = strtok(strdup(str), deliminator);
	if (!token)
	{
		printf("FAIL");
		return (NULL);
	}
	while (str[i] != '\0')
	{
		parsedarray[i] = token;
		token = strtok(NULL, deliminator);
		i++;
	}
	return (parsedarray);
}
