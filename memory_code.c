#include "shell.h"

/**
 * bfree - Free pointer and NULL address
 * @ptr: Address to be free
 * Return: if freed return 1, 0 otherwise
 */


int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
