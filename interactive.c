#include "shell.h"

/**
 * interactive - Determines if the shell is in interactive mode.
 * @info: Pointer to a struct containing relevant information.
 *
 * Return: 1 if in interactive mode, 0 otherwise.
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
