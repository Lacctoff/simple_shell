#include "shell.h"

int main(int ac, char **av);

/**
 * main - handles basic command execution
 * and provides a simple interactive shell interface.
 * @ac: arguments count.
 * @av: arguement vector.
 * Return: 0 on success
 */

int main(int ac, char **av)
{
	size_t buff_size = 0;
	char *buff = NULL;
	int i = 0;
	char *command_name;
	char *command;
	char **args;
	char *command_path;

	while (*av != NULL)
	{
		command_name = *av;
		av++;
		ac++;
	}
	command_name = str_concat(command_name, ": ");

	while (1)
	{
		/*write(1, "#cisfun$ ", 9);*/
		if (getline(&buff, &buff_size, stdin) == -1)
		{
			free(command_name);
			break;
		}

		while (is_whitespace(buff[i]))
		{
			i++;
		}

		if (buff[i] == '\0' || buff[i] == '\n')
		{
			continue;
		}

		/* Remove the newline character at the end*/
		if (buff[_strlen(buff) - 1] == '\n')
		{
			buff[_strlen(buff) - 1] = '\0';
		}

		/* Tokenize the input line into a command and its arguments */
		command = strtok(buff, " \t\n");
		args = malloc(sizeof(char *) * 1024);

		i = 0;
		while (command)
		{
			args[i] = command;
			command = strtok(NULL, " \t\n");
			i++;
		}
		args[i] = NULL;

		/*Implement the env built-in, that prints the current environment*/
		if (_strcmp(args[0], "env") == 0)
		{
			char **env = environ;

			while (*env != NULL)
			{
				write(1, *env, _strlen(*env));
				write(1, "\n", 1);
				env++;
			}
		}

		/*checks exit command is equal to the arg and exits the program*/
		if (_strcmp(args[0], "exit") == 0)
		{
			free(command_name);
			free(buff);
			free(args);
			exit(0);
		}

		/* Check if the command contains a '/' character */
		if (_strchr(args[0], '/') != NULL)
		{
			/* This is an absolute path, execute it directly */
			if (access(args[0], X_OK) == 0 && execute_command(args[0], args) == -1)
			{
				write(STDERR_FILENO, command_name, _strlen(command_name));
				perror("");
			}
		}
		else
		{
			/* Search for the command in PATH */
			command_path = search_command_in_path(args[0]);

			if (command_path)
			{
				if (execute_command(command_path, args) == -1)
				{
					write(STDERR_FILENO, command_name, _strlen(command_name));
					perror("");
				}
				free(command_path);
			}
			else
			{
				write(STDERR_FILENO, command_name, _strlen(command_name));
				perror("");
			}
		}

		i = 0;
		free(args);
	}

	free(command_name);
	free(buff);
	return (0);
}
