#include "holberton.h"
/**
  * looper - continuous shell loop
  *
  *
  *
  *
  */
void looper(__attribute__((unused))char **av)
{
	char *input;
	char **tokens;
	int status;

	status = 0;
	do {
		input = _prompt();		/*gets input stream*/
		if (input == NULL)
			status = -1;
		tokens = tokenize(input);
		if (!tokens)
		{
			status = -1;
		}

	} while (status);
	free2pointer(tokens);
}
