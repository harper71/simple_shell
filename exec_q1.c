#include "main.h"
/**
 * run_command_1 - to execute the commands
 * @cmd: takes in the arguments
 * @program_name: program_name
 * Return: 0
 */
void run_command_1(char *cmd, char *program_name)
{
	char *args[2];

	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		args[0] = cmd;

		args[1] = NULL;

		if (execve(args[0], args, NULL) == -1)
		{
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
}
