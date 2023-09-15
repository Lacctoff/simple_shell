#ifndef _MAIN_H_
#define _MAIN_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

extern char **environ;

/*Custom functions*/
char *str_concat(char *s1, char *s2);
int _strlen(char *s);
int is_whitespace(char ch);
int _strcmp(const char *str1, const char *str2);


/* Function to execute a command with arguments*/
int execute_command(char *command, char **args);

/* Function to search for the command in PATH*/
char *search_command_in_path(char *command);
char *_getenv(const char *name);
char *custom_getenv(char *name);

#endif
