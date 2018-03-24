#ifndef HOLBERTON_H
#define HOLBERTON_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
/**
  * struct tokenlist_t - linked list of parsed path variable string
  * @token: absolute path
  * @next: pointer to next node
  *
  */
typedef struct tokenlist_t
{
	char *token;
	struct tokenlist_t *next;
} tokenlist_t;
extern char **environ;
void looper(char **argv);
char *_prompt(void);
char **tokenize(char *str);
void *_realloc(void *ptr, unsigned int, unsigned int);
int launch(char **av char **tokens);
char *checkpath(char *command);
char *appendcmd(const tokenlist_t *pathlist, char *arg);
char *_strcmp(char *);
int *_strcmp2(char *s1, char *s2);
char *findpath(void);
char **pathsplit(char*);
int _strlen(char *);
tokenlist_t *tokentolist(tokenlist_t **head, char *token);
tokenlist_t *pathsplitlist(char *path);
void freelist(tokenlist_t *head);
int statcommand(char *exec);
void escape(char **argv);
int printenviron(char **argv);
void printerror(char **, static int, char **);
#endif
