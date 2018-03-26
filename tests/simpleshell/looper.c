#include "holberton.h"
/**
  * looper - continuous shell loop
  *
  *
  *
  *
  */
void looper(char **av)
{
	char *input;
	char **tokens;
	int status;
	static int count;

	count = 1;
	status = 0;
	do {
		input = _prompt();		/*gets input stream*/
		if (input == NULL)
			status = -1;
		tokens = tokenize(input);	/*splits input into tokens*/
		if (!tokens)
			status = -1;

		status = launch(av, tokens, input, count);	/*executes tokens*/
		if (status != 1)
		{
			status = -1;
		}
	count++;
	} while (status);
}
