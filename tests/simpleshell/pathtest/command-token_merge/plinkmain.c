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
  * main - turns path to link list and prints
  *
  *
  *
  */
int main (void)
{
	char *pathvar;
	tokenlist_t *pathlist;

	pathvar = findpath();	/*finds PATH string*/
	pathlist = pathsplitlist(pathvar);
	print_list(pathlist);

	return (0);
}
