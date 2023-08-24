#include "shell.h"

/**
 * _strlen - gives the length of a string
 * @s: the string length to be checkec
 * Return: integer length of string
 */

int _strlen(char *s)
{
	int z = 0;

	if (!s)
		return (0);

	while (*s++)
		z++;
	return (z);
}

/**
 * starts_with - performs a check to see if needle starts with an haystack
 * @needle: the substring to find
 * @haystack: the string to search
 * Return: returns the address of the next char of haystack
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - adds two strings together
 * @src: the source buff
 * @dest: the destination buff
 * Return: pointer to destination buff
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

/**
 * _strcmp - exicogarphic comparison of two strangs.
 * @s1: strang 1
 * @s2: strang 2
 * Return: negative if s1 is less than s2, positive if s1 is greater than s2, and zero if s1 is equal to s2
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
