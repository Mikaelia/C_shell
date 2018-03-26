#include "holberton.h"
/**
  * _itos - converts integer to string
  *
  *
  *
  *
  */
char *_itos(int num)
{
	int mult, count, i, len;
	unsigned int numcopy;
	unsigned int n;
	char *new;

	mult = 1;
	count = 1;
	i = 0;

	n = num;
	numcopy = num;

	while (numcopy >= 10)
	{
		numcopy /= 10;
		mult *= 10;
		count++;
	}
	len = count + 1;
	new = malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	while (count > 1)
	{
		if ((n / mult) < 10)
		{
			new[i] = ((n / mult + '0'));
		}
		else
		{
			new[i] = (((n / mult) % 10) + '0');
		}
		count--;
		mult /= 10;
		i++;
	}
	new[i] = (n % 10 + '0');
	new[++i] = '\0';
	return (new);
}

/**
  * _len - finds length of string
  * @str - input string
  *
  * Return: length of string
  */
int _len(char *str)
{
	int i;

	i = 0;
	while (str[i] != 0)
	{
		i++;
	}
	return (i);
}
/**
  * printerror - prints error message
  * @arg: main argument list
  * @arc: number of arguments executed
  * @line: input from prompt
  *
  * Return: void
  */
void printerror(char **arg, int count, char *line)
{
	char *c = _itos(count);

	write(STDOUT_FILENO, arg[0], _len(arg[0]));
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
	write(STDOUT_FILENO, c, _len(c));
	write(STDOUT_FILENO, ": ", sizeof(char) * 2);
	write(STDOUT_FILENO, line, _len(line));
	write(STDOUT_FILENO, ": not found\n", sizeof(char) * 13);
	free(c);
}
