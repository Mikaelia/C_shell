#include "holberton.h"
int main(void)
{
	char **s;
	int i;
	char a[12] = "Hello there";

	s = tokenize(a);

	for (i = 0; s[i] != NULL; i++)
	{
		printf("%s\n", s[i]);
	}

	return (0);
}
