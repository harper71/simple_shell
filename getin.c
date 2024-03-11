#include "main.h"
/**
 * get_input - used to get user input
 * Return: prompt
 */
char *get_input()
{
	char *prompt = NULL;

	size_t len_var = 0;

	ssize_t read = getline(&prompt, &len_var, stdin);

	if (read == -1)
	{
		if (errno == 0 || errno == EOF)
		{
			free(prompt);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(prompt);
			exit(EXIT_SUCCESS);
		}
	}

	prompt[strcspn(prompt, "\n")] = '\0';

	return (prompt);
}
