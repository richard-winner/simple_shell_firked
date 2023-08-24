#include "shell.h"

/**
 * list_len - Length of linked list is determined
 * @h: First node Pointer
 * Return: list size
 */

size_t list_len(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * get_node_index - Index of node is given
 * @node: Node pointer
 * @head: List head pointer
 * Return: -1 or index of node
 */


ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t r = 0;

	while (head)
	{
		if (head == node)
			return (r);
		head = head->next;
		r++;
	}
	return (-1);
}

/**
 * list_to_strings - Array of strings of the list->str is retured.
 * @head: First node Pointer
 * Return: str array
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t a = list_len(head), b;
	char **strs;
	char *str;

	if (!head || !a)
		return (NULL);
	strs = malloc(sizeof(char *) * (a + 1));
	if (!strs)
		return (NULL);
	for (a = 0; node; node = node->next, a++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (b = 0; b < a; b++)
				free(strs[b]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[a] = str;
	}
	strs[a] = NULL;
	return (strs);
}

/**
 * print_list - All elements of a list_t linked lst are Printed
 * @h: First node pointer
 * Return: List size
 */

size_t print_list(const list_t *h)
{
	size_t a = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		a++;
	}
	return (a);
}

/**
 * node_starts_with - Node whose string starts with prefix is Retured
 * @node: List head pointer
 * @c: Next char prefix to be match
 * @prefix: str to be matched
 * Return: Node match or NULL
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}
