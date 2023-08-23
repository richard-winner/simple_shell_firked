#include "shell.h"
/**
 * _eputs - this function prints an input string
 * @str: this is the string to be printed
 * Return: nay
 */
void _eputs(char *str)
{
	int v = 0;

	if (!str)
		return;
	while (str[v] != '\0')
	{
		_eputchar(str[v]);
		v++;
	}
}
/**
 * _eputchar - function writes the character c to stderr
 * @c: character to be printed
 * Return: On success return 1, else
 * return -1 and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
	{
		write(2, buf, v);
		v = 0;
	}
	if (c != BUF_FLUSH)
		buf[v++] = c;
	return (1);
}

/**
 * _putfd - the function here writes the character c to given fd
 * @c: this is the character to be printed
 * @fd: this is the filedescriptor to write to
 * Return: On success, return 1,
 * error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || v >= WRITE_BUF_SIZE)
	{
		write(fd, buf, v);
		v = 0;
	}
	if (c != BUF_FLUSH)
		buf[v++] = c;
	return (1);
}

/**
 * _putsfd - this function here prints an input string
 * @str: this is the string to be printed
 * @fd: this is the filedescriptor to write to
 * Return: here is the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int v = 0;

	if (!str)
		return (0);
	while (*str)
	{
		v += _putfd(*str++, fd);
	}
	return (v);
}
