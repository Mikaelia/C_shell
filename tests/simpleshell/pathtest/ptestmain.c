#include "holberton.h"
/**
  * main - main function for simple shell
  *
  *
  *
  */
int main (void)
{
	char *pathvar;

	pathvar = findpath();	/*finds PATH string*/
	printf("%s\n", pathvar);

	return (0);
}
