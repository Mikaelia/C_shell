#include "holberton.h"
/**
 * _realloc - function that reallocates  memory space
 * @ptr: input string
 * @original: original size of  memory space
 * @resized: resized  memory space
 * Return: NULL or string
 */
void *_realloc(void *ptr, unsigned int original, unsigned int resized)
{
	char *newbuf;
	void *vptr;
	char *tmp;
	unsigned int i;

	if (original == resized)
		return (ptr);
	if (resized == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
	{
		return (malloc(resized));
	}
	tmp = ptr;
	newbuf = malloc(resized);
	if (newbuf == NULL)
		return (NULL);

	if (resized > original)
	{
		for (i = 0; i < original; i++)
			newbuf[i] = tmp[i];
		free(ptr);
	}
	if (resized < original)
	{
		for (i = 0; i < resized; i++)
			newbuf[i] = tmp[i];
		free(ptr);
	}
	vptr = newbuf;
	return (vptr);
}
