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
		tokens = tokenize(input);	/*splits input into tokens*/
		status = launch(tokens);	/*executes tokens*/

		free(input);
		free(tokens);
	} while (status);
}
