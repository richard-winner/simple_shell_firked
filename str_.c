#include "shell.h"

/**
 * _strlen - Str length is retured 
 * @s: Length of a string to be checked
 * Return: Length of str
 */

int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
 * _strcmp - Perforns comparisim between 2 strs
 * @s1: first str
 * @s2: second str
 * Return:  It returns, Positive if s1 > s2, Negative if s1 < s2, Zero if s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - To know if needle starts with haystack or not
 * @needle: Substr to be searched for
 * @haystack: Str to searched
 * Return: Returns the address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concats two str
 * @src: The source the buff
 * @dest: Destination of a buff
 * Return: Pointer to the destination of a buff
 */


char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

