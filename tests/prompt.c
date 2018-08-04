#include "holberton.h"
/**
  * _prompt - reads line for prompt
  *
  *
  */
char *_prompt(void)
{
  char *line = NULL;
  int s;
  size_t bufsize = 0;

  printf("$ ");
  s = getline(&line, &bufsize, stdin); /*stores address of buffer containing args*/
  if (s == -1)
	  perror("ERROR");
  return (line);
}
