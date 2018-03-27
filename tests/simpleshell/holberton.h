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

void free2pointer(char **tokens);
void freelist(tokenlist_t *head);

extern char **environ;
unsigned int flag;

void sig_handler(int sig_handler);
void looper(char **);
int _prompt(char **);
char **tokenize(char *str);
void *_realloc(void *ptr, unsigned int, unsigned int);
int launch(char **av, char **tokens, char *input, int count);
/*checkfunctions*/
int checkbuiltins(char **tokens, char *line);
char *checkpath(char *command);
char *appendcmd(const tokenlist_t *pathlist, char *arg);
char *_findpath(char *);
char *findpath(void);
char **pathsplit(char*);
int _strlen(char *);
int _strcmp(char *s1, char *s2);
tokenlist_t *tokentolist(tokenlist_t **head, char *token);
tokenlist_t *pathsplitlist(char *path);
int statcommand(char *exec);
int __exit(char **tokens, char *line);
int printenviron(char **tokens);
void printerror(char **, int, char *);
char *_strdup(char *);
#endif
