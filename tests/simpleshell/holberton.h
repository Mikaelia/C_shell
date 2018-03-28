#ifndef HOLBERTON_H
#define HOLBERTON_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
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

typedef struct free_t
{
	char **commands;
	char *token;
	char *input;
	char *executable;
	char *pathvar;
} free_t;

/* free functions */

void free2pointer(char **tokens);
void freelist(tokenlist_t *head);
void free2list(char **);

/*global variables */

extern char **environ;
unsigned int flag;

/* helper functions */
void sig_handler(int sig_handler);
char *_realloc(void *ptr, unsigned int, unsigned int);
int _strlen(char *);
int _strcmp(char *s1, char *s2);
void printerror(char **, int, char *);
char *_strdup(char *);

/* main functions */
void looper(char **);
int _prompt(char **, free_t *stash);
int tokenize(free_t *stash);
void launch(char **av, free_t *stash, int count);

/*checkfunctions*/
int checkbuiltins(char **tokens, char *line);
char *checkpath(free_t *stash);
char *appendcmd(const tokenlist_t *pathlist, char *arg);
char *_findpath(char *);
char *findpath(void);
char **pathsplit(char*);
tokenlist_t *tokentolist(tokenlist_t **head, char *token);
tokenlist_t *pathsplitlist(char *path);

/* builtins */
int __exit(char **tokens, char *line);
int printenviron(char **tokens);
#endif
