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

	status = 0;
	do {
		input = _prompt();		/*gets input stream*/
		if (input == NULL)
			status = -1;
		tokens = tokenize(input);	/*splits input into tokens*/
		if (!tokens)
			status = -1;
		status = launch(tokens);	/*executes tokens*/
		if (status != 1)
			status = -1;

		free(input);
		free(tokens);
	} while (status);
}
