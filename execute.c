#include "main.h"
/**
 * execute_command - to execute the commands
 * @args: takes in the arguments
 * Return: 0
 */
int execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			dprintf(STDERR_FILENO, "%s: command not found\n", args[0]);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
