#include "shell.h"


/**
 * ffree - frees a str of other str
 * @pp: str of strs
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _memset - Use constant byte in filling memory
 * @b: *s, the byte to be filled witht
 * @n: byte amount to be filled 
 * @s: Memory area poionter
 * Return: A pointer is returned on memory area s
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;
	return (s);
}

/**
 * _realloc - Reallocates a memory block
 * @old_size: Previous block byte size
 * @new_size: New block byte size
 * @ptr: Pointer to former malloc block
 * Return: pointer to the allocated block
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}

