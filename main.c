#include "main.h"
/**
 * main - shell implementation of task
 * @argc: argument count
 *
 * @argv: argument vector
 *
 * Return: 0 always
 */
int main(void)
{
	char *prompt;

	while (1)
	{
		prompt = get_command();

		if (prompt == NULL)
		{
			break;
		}
		run_command_1(prompt);
		free(prompt);
	}
	return (0);
}
