#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(char *argv[])
{
    	char *newargv[] = { NULL, "hello", "there", NULL };
    	char *newenviron[] = { NULL };

   	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s <file-to-exec>\n", argv[0]);
	exit(EXIT_FAILURE);

	}
	newargv[0] = argv[1];

	execve(argv[1], newargv, newenviron);
	perror("execve"); /* execve() only returns on error */
	exit(EXIT_FAILURE);
}