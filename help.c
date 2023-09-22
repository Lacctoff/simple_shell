#include "shell.h"

/**
 * _myhelp - Displays help information for the shell.
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 *
 * Return: Always 0.
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	puts("help call works. Function not yet implemented \n");
	if (0)
		puts(*arg_array);
	return (0);
}
