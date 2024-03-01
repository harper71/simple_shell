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
		exit(EXIT_FAILURE);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
