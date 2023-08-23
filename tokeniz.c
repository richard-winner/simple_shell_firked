#include "shell.h"

/*
 * strtow - Used in splitting strings into words
 * @d: Str delimeter
 * @str: String input
 * Return: Pointer to array of str, on failure return NULL
 */

char **strtow(char *str, char *d)
{
	int i, b, c, e, Numword = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (i = 0; str[i] != '\0'; i++)
		if (!is_delim(str[i], d) && (is_delim(str[i + 1], d) || !str[i + 1]))
			Numword++;

	if (Numword == 0)
		return (NULL);
	s = malloc((1 + Numword) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, b = 0; b < Numword; b++)
	{
		while (is_delim(str[i], d))
			i++;
		c = 0;
		while (!is_delim(str[i + c], d) && str[i + c])
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			s[b][e] = str[i++];
		s[b][e] = 0;
	}
	s[b] = NULL;
	return (s);
}

/*
 * strtow - Used in splitting strings into words
 * @d: Str delimeter
 * @str: String input
 * Return: Return: Pointer to array of str, on failure return NULL
 */

char **strtow2(char *str, char d)
{
	int i, b, c, e, Numword = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
				    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			Numword++;
	if (Numword == 0)
		return (NULL);
	s = malloc((1 + Numword) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, b = 0; b < Numword; b++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		c = 0;
		while (str[i + c] != d && str[i + c] && str[i + c] != d)
			c++;
		s[b] = malloc((c + 1) * sizeof(char));
		if (!s[b])
		{
			for (c = 0; c < b; c++)
				free(s[c]);
			free(s);
			return (NULL);
		}
		for (e = 0; e < c; e++)
			s[b][e] = str[i++];
		s[b][e] = 0;
	}
	s[b] = NULL;
	return (s);
}

