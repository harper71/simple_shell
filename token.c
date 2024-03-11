#include "main.h"
/**
 * parse_input - tokenize the string
 * @input: command line prompt
 * Return: args
 */
char **parse_input(char *input)
{
	char **args = NULL, *token = NULL, *delm = " \t\n";

	int i = 0;

	args = malloc(MAX_ARGS * sizeof(char *));

	if (args == NULL)
	{
		fprintf(stderr, "Memory allocation failed\n");
		return (NULL);
	}

	token = strtok(input, delm);

	while (token != NULL && i < (MAX_ARGS - 1))
	{
		args[i] = token;
		i++;
		token = strtok(NULL, delm);
	}
	args[i] = NULL;

	return (args);
}
