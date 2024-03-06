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

extern char **environ;

void print_environment();
void prompt(void);
char **parse_args(char *line);
int parse_command(char *command);
int is_empty_line(char *line);
char *get_command();
void execute_command(char **command_line);
int _printf(const char *format, ...);
void execute_with_custom_env(void);
void execute_command_if_found(char **args);
#endif
