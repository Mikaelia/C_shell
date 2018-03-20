#include "holberton.h"
int main(void)
{
	int val;
	char *s;

	s = "";
	val = 0;

	val = _strcmp(s);
	if (val == 1)
		printf("Found it!\n");
	else
		printf("Match not found for %s\n", s);

	return (0);
}
