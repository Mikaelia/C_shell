#include "holberton.h"
#include <unistd.h>
#include <stdio.h>

void test(char **env)
{
	int i = 0;

	printf("Now the memory address of env is %i", **env);
	while (env[i] != NULL)
	{
		printf("Passing in env variable: %s\n", env[i]);
		i++;
	}
}


int main (int argc, char **argv, char **env)
{

printf("The memory address of env is %i", **env);
test(env);


}
