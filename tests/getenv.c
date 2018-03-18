#include <stdio.h>

/**
 * main - prints the environment
 *
 * Return: Always 0.
 */
int main(int ac, char **av, char **env)
{
    unsigned int i, j;
    char varname[6];
    int count;
    char *var = "PATH=";

    i = 0;
    j = 0;
    count = 0;
    while (env[i] != NULL)
    {
	    while (count < 6 && env[i][j] != '\0')
	    {
		    varname[count] = env[i][j];
		    j++;
	    }

        printf("%s\n", env[i]);
        i++;
    }
    return (0);
}
