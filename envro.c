#include "main.h"
/**
 * execute_with_custom_env - Executes the `env` command with custom environment
 */
void execute_with_custom_env(void)
{
	char *argv[2];

	char **env;

	argv[0] = "/usr/bin/env";

	argv[1] = NULL;

	for (env = environ; *env != NULL; env++)
	{
		_printf("%s\n", *env);
	}
	if (execve("/usr/bin/env", argv, NULL) == -1)
	{
		exit(EXIT_FAILURE);
	}
}
