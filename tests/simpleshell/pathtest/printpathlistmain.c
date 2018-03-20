#include "holberton.h"
/**
  * print_list - prints all elements of a list
  * @h: header node
  *
  * Return: the number of nodes
  */
void print_list(const tokenlist_t *h)
{

	while (h != NULL)
	{
		printf("%s\n", h->token);
		h = h->next;
	}
}
/**
  * main - main function for simple shell
  *
  *
  *
  */
int main (void)
{
	char *pathvar;
	tokenlist_t *pathlist;

	pathvar = findpath();	/*finds PATH string*/
	pathlist = pathsplitlist(pathvar); /*returns pointer to head*/
	print_list(pathlist);
	freelist(pathlist);

	return (0);
}
