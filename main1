#include "main.h"
/**
 * main - shell implementation of task 1
 * Return: 0 always
 */
int main(void)
{
	char *command_line, **args;

	int result;

	while (1)
	{
		print_prompt();

		command_line = get_command();

		args = parse_args(command_line);

		result = execute_command(args);

		if (result == -1)
		{
			break;
		}

		free(command_line);
		free(args);
	}
	return (0);
}
