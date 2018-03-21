#include "holberton.h"
/**
  * pathsplit - splits path into tokens
  *
  * Return: Array of each word of string
  */
char **pathsplit(char *path)
{
	char **patharray;
	char *pathtoken;
	const char *deliminator  = ":";
	int i, j;
	int bufsize;

	bufsize = 2;
	i = 0;
	j = 0;

	if (!path)
	{
		perror("Null input string");
		return (NULL);
	}
	while (path[i] != '\0')					/*counting ':' to determine needed bufsize*/
	{
		if (path[i] == deliminator[0])
			bufsize++;
		i++;
	}
	patharray = malloc(sizeof(char*) * bufsize);		/*allocate space for new array of pointers*/
	if (patharray == NULL)
	{
		perror("ALLOCATION ERROR");
		return (NULL);
	}
	pathtoken = strtok(path, deliminator);			/*initial tokenization*/
	if (!pathtoken)
	{
		perror("TOKEN FAIL");
		free(patharray);
		return (NULL);
	}
	while (pathtoken != NULL)				/*strtok will return NULL at end of string*/
	{
		patharray[j] = pathtoken;			/*filling new buff with tokens*/
		pathtoken = strtok(NULL, deliminator);
		j++;
	}
	patharray[j] = '\0';
	return (patharray);
}
