#include "main.h"
/**
 * get_command - print the prompt sign
 * Return: prompt
 */
char *get_command()
{
	char *prompt = NULL;

	size_t lenVar = 0;

	if (getline(&prompt, &lenVar, stdin) == -1)
	{
		if (EOF)
		{
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}

	prompt[strcspn(prompt, "\n")] = '\0';

	return (prompt);
}
