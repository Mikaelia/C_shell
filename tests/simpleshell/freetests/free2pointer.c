#include "holberton.h"
/**
  * free2pointer - frees a double pointer
  *
  *
  *
  * Return: void
  */
void free2pointer(char **tokens)
{
	int i;

	for (i = 0; tokens[i] != NULL; i++)
	{
		    free(tokens[i]);
	}
	free(tokens);
}