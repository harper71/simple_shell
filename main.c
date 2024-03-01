#include "main.h"
/**
 * main - shell implementation of task
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
		if (strcmp(prompt, "exit") == 0)
		{
			break;
		}
		free(prompt);
	}
	return (0);
}
