#include "main.h"
/**
 * shell_2 - used to create a command shell enviroment
 * @av: arguments
 *
 */
void shell_2(char *av[])
{
	char *prompt = NULL, *str_cpy = NULL;

	char *delm = " \n";

	size_t lenVar = 0;

	int var, len_prompt, i, argc;

	char *token = NULL, **argv = NULL;

	pid_t pid;

	printf("$ ");
	while (getline(&prompt, &lenVar, stdin) != EOF)
	{
		len_prompt = strlen(prompt);

		prompt[len_prompt - 1] = '\0';

		str_cpy = strdup(prompt);

		argc = 0;

		token = strtok(prompt, delm);

		while (token)
		{
			token = strtok(NULL, delm);

			argc++;
		}
		argv = malloc(sizeof(char *) * (argc + 1));

		if (argv == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		token = strtok(str_cpy, delm);

		i = 0;

		while (token)
		{
			argv[i] = token;

			token = strtok(NULL, delm);
			i++;
		}
		argv[i] = NULL;

		pid = fork();
		if (pid == -1)
		{
			perror("can't create the child process");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			var = execve(argv[0], argv, NULL);

			if (var == -1)
			{
				printf("%s: no such directory\n", av[0]);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
		printf("$ ");
		free(argv);
		free(str_cpy);
	}
	free(prompt);
}

