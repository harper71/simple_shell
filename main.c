#include "main.h"
/**
 * main - shell implementation of task
 * @argc: argument count
 *
 * @argv: argument vector
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	char *prompt;

	argc = 0;

	while (1)
	{
		prompt = get_command();

		if (prompt == NULL)
		{
			break;
		}
		run_command_1(prompt, argv[argc]);
		free(prompt);
	}
	return (0);
}
