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


#define BUFFER_SIZE 1024

void print_prompt(void);
char *get_command();
char **parse_args(char *line);
int is_empty_line(char *line);
int execute_command(char **args, char *project_name);
int _printf(const char *format, ...);
void tokenize_command(char *prompt, char **cmd);
void run_command_1(char *cmd, char *program_name);
#endif/* MAIN_H */
