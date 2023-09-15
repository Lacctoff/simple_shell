#include "main.h"

/**
 * execute_command - this function excecutes the command passed
 * in by the user input.
 * @command: commands
 * @args: the arguements passed in with the command.
 *
 *
 * Return: 0 on success.
 */

int execute_command(char *command, char **args)
{
	pid_t child_pid;
	int status;
	char *envp[] = {NULL};

	child_pid = fork();

	if (child_pid == 0)
	{
		/* Child process */
		if (execve(command, args, envp) == -1)
		{
			perror("Error with execve");
			exit(EXIT_FAILURE);
		}
	}
	else if (child_pid > 0)
	{
		/* Parent process */
		wait(&status);
	}
	else
	{
		perror("Fork error");
		return (-1);
	}

	return (0);
}
