#include "main.h"
/**
 * execute_command - to execute the commands
 * @args: takes in the arguments
 * @project_name: the name of the file.
 * Return: 0
 */
int execute_command(char **args, char *project_name)
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
			_printf("%s: No such file or directory\n", project_name);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	return (0);
}
