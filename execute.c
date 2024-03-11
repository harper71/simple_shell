#include "main.h"
/**
 * execute_command - to execute the commands
 * @argv: program name
 * @command_line: command parsed
 */
void execute_command(char **command_line, char **argv)
{
	pid_t pid;

	char *full_path = NULL;

	full_path = search_path(command_line[0], argv);

	if (strchr(command_line[0], '/') != NULL)
	{
		pid = fork();
		if (pid == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command_line[0]);
			free(command_line);
		}
		else if (pid == 0)
		{
			execve(command_line[0], command_line, NULL);
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command_line[0]);
			exit(127);
		}
		else
		{
			wait(NULL);
		}
	}
	else if (strcmp(command_line[0], "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (full_path == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command_line[0]);
			free(command_line);
			exit(127);
		}
		pid = fork();
		if (pid == -1)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command_line[0]);
			exit(127);
		}
		else if (pid == 0)
		{
			execve(full_path, command_line, NULL);
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command_line[0]);
			exit(127);
		}
		else
		{
			free(full_path);
			wait(NULL);
		}
	}

}
