#include "holberton.h"
/**
  * _prompt - reads line for prompt
  *
  *
  */
int _prompt(void)
{
  char *line = NULL;
  size_t bufsize = 0;

  printf("$ ");
  while (getline(&line, &bufsize, stdin) != -1)
  {
	printf("%s", line);
  }
  free(line);
  return 0;
}
