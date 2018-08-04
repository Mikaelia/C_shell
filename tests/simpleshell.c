#include "holberton.h"
/**
  * main - super simple shell program
  *
  *
  *
  *
  */
int main(void)
{
	char *input;
	char **tokens;
	int status;

	input = _prompt();
	tokens = tokenize(input);
	status = launch(tokens);

	free(input);
	free(tokens);

	printf("%d", status);

	return (0);
}
