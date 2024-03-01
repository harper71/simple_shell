#include "main.h"
/**
 * get_command - print the prompt sign
 * Return: prompt
 */
char *get_command()
{
	char *prompt = NULL;

	size_t lenVar = 0, len_prompt;

	if (getline(&prompt, &lenVar, stdin) == -1)
	{
		exit(EXIT_SUCCESS);
	}
	len_prompt = strlen(prompt);

	prompt[len_prompt - 1] = '\0';

	prompt[strcspn(prompt, "\n")] = '\0';

	return (prompt);
}
