#include "holberton.h"
/**
  * looper - continuous shell loop
  *
  *
  *
  *
  */
void looper(void)
{
	char *input;
	char **tokens;
	int status;
	do
	{
		input = _prompt();
		tokens = tokenize(input);
		status = launch(tokens);

		free(input);
		free(tokens);
	} while (status);
}
