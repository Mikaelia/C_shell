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
	int x;

	x = 0;

	count = 1;
	do {
		status = 0;
		input = NULL;
		tokens = NULL;

		x = _prompt(&input);
		printf("%d\n", x);
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
		free(*tokens);
		free(tokens);
	} while (status);
}
