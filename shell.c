#include "main.h"
/**
 * shell_1 - used to create a command shell enviroment
 * @av: arguments
 *
 */
void shell_1(char *av[])
{
	char *prompt = NULL;

	size_t lenVar = 0;

	char *cmd[2];

	int var, len_prompt;


	pid_t pid;

	write(1, "$ ", 2);
	while (getline(&prompt, &lenVar, stdin) != EOF)
	{
		len_prompt = strlen(prompt);

		prompt[len_prompt - 1] = '\0';

		pid = fork();

		if (pid == 0)
		{
			cmd[0] = prompt;

			cmd[1] = NULL;

			var = execve(cmd[0], cmd, NULL);

			if (var == -1)
			{
				dprintf(STDOUT_FILENO, "%s: no such directory\n", av[0]);
			}
			break;
		}
		else
		{
			wait(NULL);
		}
		write(1, "$ ", 2);
	}
	free(prompt);
}
