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
		free(prompt);
		exit(EXIT_SUCCESS);
	}

	prompt[strcspn(prompt, "\n")] = '\0';

	return (prompt);
}
