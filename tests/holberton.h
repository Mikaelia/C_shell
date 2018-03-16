#ifndef HOLBERTON_H
#define HOLBERTON_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int _prompt(void);
char **tokenize(char *str);
void *_realloc(void *ptr, unsigned int, unsigned int);
#endif
