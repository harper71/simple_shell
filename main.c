#include "main.h"
/**
 * main - shell structure
 * @argc: arg count
 * @argv: arg vector
 * Return: 0 always
 */
int main(int argc, char **argv)
{
	char **args, *input;

	while (1)
	{
		input = get_input();

		args = parse_input(input);

		if (args[0] != NULL)
		{
			execute_command(args, argv);
		}
		free(input);
		free(args);
	}
	(void)argc;
	return (0);
}
