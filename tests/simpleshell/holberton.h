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
#endif
