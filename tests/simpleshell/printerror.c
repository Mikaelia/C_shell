#include "holberton.h"
/**
  * printerror - prints error for invalid command
  *
  *
  * Return: 0
  */
void printerror(char **av, int count, char **tokens)
{
	write(STDOUT_FILENO, av[0], _strlen(av[0]));
}
