#include "holberton.h"
/**
  * looper - continuous shell loop
  *
  *
  *
  *
  */
void looper(char **env)
{
	char *input;
	char *pathvar;
	char **tokens;
	int status;

	status = 0;
	do
	{
		input = _prompt();		/*gets input stream*/
		pathvar = findpath(env);	/*finds PATH value*/
		tokens = tokenize(input);	/*splits input into tokens*/
		status = launch(tokens);	/*executes tokens*/

		free(input);
		free(tokens);
	} while (status);
}
