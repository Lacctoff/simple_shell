#include "shell.h"

/**
 * search_command_in_path - searches for an ex command within the directrories
 * listed in the PATH environment.
 *
 * @command: the excecutable command to search for
 * Return: NULL if command not found and returns command_path if X_OK == 0.
 */

void *search_command_in_path(char *command)
{
	char *path = custom_getenv("PATH");
	char *path_copy = _strdup(path);
	char *dir = strtok(path_copy, ":");
	char *command_path = NULL;

	while (dir != NULL)
	{
		command_path = str_concat(dir, "/");
		command_path = str_concat(command_path, command);

		if (access(command_path, X_OK) == 0)
		{
			free(path_copy);
			return (command_path);
		}

		free(command_path);
		dir = strtok(NULL, ":");
	}

	free(path_copy);
	return (NULL);
}
