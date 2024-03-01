#include "main.h"
/**
 * get_command - print the prompt sign
 * @prompt: receive prompt from user
 */
char *get_command()
{
	char *prompt = NULL;

	size_t lenVar = 0;

	if (getline(&prompt, &lenVar, stdin) == -1)
	{
		exit(EXIT_SUCCESS);
	}
	prompt[strcspn(prompt, "\n")] = '\0';

	return (prompt);
}
