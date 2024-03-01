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



#define BUFFER_SIZE 1024

void print_prompt(void);
char *get_command();
char **parse_args(char *line);
int is_empty_line(char *line);
int execute_command(char **args);

#endif/* MAIN_H */
