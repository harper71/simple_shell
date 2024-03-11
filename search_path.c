#include "main.h"
/**
 * search_path - search for the path
 * @command: command to pass to path
 * Return: NULL
 */
char *search_path(char *command, char *argv[])
{
	char *path = NULL, *path_copy = NULL, *dir = NULL, *full_path = NULL;

	path = getenv("PATH");

	if (path == NULL)
	{
		return (NULL);
	}

	path_copy = strdup(path);

	if (path_copy == NULL)
	{
		free(path_copy);
		return (NULL);
	}

	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);

		if (full_path == NULL)
		{
			fprintf(stderr, "%s: 1: %s: not found\n", argv[0], command);
			free(path_copy);
			return (NULL);
		}
		sprintf(full_path, "%s/%s", dir, command);
		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			return (full_path);
		}
		free(full_path);

		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
