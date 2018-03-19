#ifndef HOLBERTON_H
#define HOLBERTON_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
void looper(char**);
char *_prompt(void);
char **tokenize(char* str);
void *_realloc(void *ptr, unsigned int, unsigned int);
int launch(char **tokens);
char* _strcmp(char*);
char *findpath();
char **pathsplit(char*);
typedef struct tokenlist_t
{
	char *token;
	struct tokenlist_t *next;
} tokenlist_t;
tokenlist_t *tokentolist(tokenlist_t **head, char *token);
tokenlist_t *pathsplitlist(char *path);
#endif
