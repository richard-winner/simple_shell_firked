#include "shell.h"

/**
 * _strcpy - this copies a string
 * @src: source
 * @dest: destination
 * Return: points to the destination
 */

char *_strcpy(char *dest, char *src)
{
	int t = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[t])
	{
		dest[t] = src[t];
		t++;
	}
	dest[t] = 0;
	return (dest);
}

/**
 * _puts - this prints an input string
 * @str: string to be printed
 * Return: NULL
 */

void _puts(char *str)
{
	int n = 0;

	if (!str)
		return;
	while (str[n] != '\0')
	{
		_putchar(str[n]);
		n++;
	}
}

/**
 * _putchar - writes the char c to stdout
 * @c: character to be printed
 * Return: returns 1 on success and returns -1 on error
 */

int _putchar(char c)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (c != BUF_FLUSH)
		buf[m++] = c;
	return (1);
}

/**
 * _strdup - this duplicates a string
 * @str: string to be duplicated
 * Return: points to the duplicated string
 */

char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}
