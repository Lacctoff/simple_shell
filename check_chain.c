#include "shell.h"

/**
 * check_chain - Examines whether we should continue
 * chaining based on the previous status.
 * @info: The parameter structure.
 * @buf: The character buffer.
 * @p: Address of the current position within the buffer.
 * @i: Starting position within the buffer.
 * @len: Length of the buffer."
 *
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t j = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			j = len;
		}
	}

	*p = j;
}
