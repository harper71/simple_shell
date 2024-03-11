#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <errno.h>
#define MAX_COMMAND_LENGTH 100

#define MAX_ARGS 10

extern char **environ;
/*void execute_command(char **argv);*/
/*char **tokenize_command(char *command, int *argc);*/
/*void get_command(char **prompt);*/
void execute_command(char **command_line, char *argv[]);
char *search_path(char *command, char *argv[]);
char **parse_input(char *input);
char *get_input();
char *execute_command_if_found(char *args);
void execute_with_custom_env(void);
int _printf(const char *format, ...);
#endif/* MAIN_H */
