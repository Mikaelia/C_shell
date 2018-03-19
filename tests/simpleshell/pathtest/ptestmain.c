#include "holberton.h"
/**
  * main - main function for simple shell
  *
  *
  *
  */
int main (__attribute((unused))int argc, __attribute((unused))char **argv, char **env)
{
	char *pathvar;

	pathvar = findpath(env);	/*finds PATH string*/
	printf("%s\n", pathvar);

	return (0);
}
