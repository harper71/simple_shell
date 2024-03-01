#include "main.h"
/**
 * parse_args - parses arguments and tokenize
 * @line: get the command
 * Return: args
 */
char **parse_args(char *line)
{
	char **args;

	char *token, *delm = " ";

	int i = 0;

	token = strtok(line, delm);

	args = malloc(sizeof(char *) * (i + 1));

	if (args == NULL)
	{
		free(args);
		exit(EXIT_FAILURE);
	}
	while (token != NULL)
	{
		args[i++] = token;

		token = strtok(NULL, delm);
	}
	args[i] = NULL;

	return (args);
}
