#include <stdio.h>
/**
  * main - print all arguments
  * @argc: argument count
  * @argv: array of arguments
  *
  * Return: arguments entered
  */
int main(__attribute__((unused))int ac, char **av)
{
	int i = 0;
	while (av[++i] != '\0')
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
