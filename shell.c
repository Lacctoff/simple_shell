#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

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
	char *token;
	int i = 0;
	char **array;
	int status;
	pid_t child_pid;
	char *command_name;

	while (*av != NULL)
	{
		command_name = *av;
		av++;
		ac++;
	}
	command_name = str_concat(command_name, ": ");

	while (1)
	{
		write(1, "#cisfun$ ", 9);
		/*getline(&buff, &buff_size, stdin);*/
		if (getline(&buff, &buff_size, stdin) == -1)
		{
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

		token = strtok(buff, "\t\n");
		array = malloc(sizeof(char *) * 1024);

		while (token)
		{
			array[i] = token;
			token = strtok(NULL, "\t\n");
			i++;
		}
		array[i] = NULL;
		child_pid = fork();

		if (child_pid == 0)
		{
			if (execve(array[0], array, NULL) == -1)
			{
				write(STDERR_FILENO, command_name, _strlen(command_name));
				perror("");
			}
			exit(EXIT_FAILURE);
		}
		else if (child_pid > 0)
		{
			wait(&status);
		}
		else
		{
			write(STDERR_FILENO, command_name, _strlen(command_name));
			perror("");
		}

		i = 0;
		free(array);
	}
	return (0);
}
