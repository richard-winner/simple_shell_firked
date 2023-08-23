#include "shell.h"
/**
 * interactive - this function returns true if shell is interactive mode
 * @info: the struct address
 * Return: should return 1 if interactive mode, else 0
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
 * is_delim - this function her checks if character is delimeter
 * @c: the character to run the check
 * @delim: this is a delimeter string
 * Return: should return 1 if true, else 0
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}
/**
 * _isalpha - this function here checks for an alphabetical character
 * @c: this is the character to be inputed
 * Return: should return 1 if c is alphabetic, else 0
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/**
 * _atoi - this here converts the string to an integer value
 * @s: this is the string to be converted
 * Return: this should return 0 if no numbers in string, else converted number
 */
int _atoi(char *s)
{
	int v, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (v = 0; s[v] != '\0' && flag != 2; v++)
	{
		if (s[v] == '-')
			sign *= -1;

		if (s[v] >= '0' && s[v] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[v] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
/**
 **_strncpy -the function here copies a string
 *@dest: this is the destination string to be copied to
 *@src: thi is the source string
 *@n: this is the amount of characters to be copied
 *Return: return the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - the function concatenates two strings
 *@dest: this is the first string
 *@src: this is the second string
 *@n: this is the amount of bytes to be maximally used
 *Return: return the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr - the function locates a character in a string
 *@s: this is the string to be parsed
 *@c: this is the character to look for
 *Return: the (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
