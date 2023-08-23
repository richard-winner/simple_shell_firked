#include "shell.h"



/**
 * list_to_strings - List string array is retured
 * @head: First node pointer
 * Return: Strings's array
 */


char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), l;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (l = 0; l < i; l++)
				free(strs[l]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * list_len - To knoe the len of list
 * @h: First node pointer
 * Return: list's size
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
 * print_list - Used in the printing of all elements of the list_t linked list
 * @h: First node pointer
 * Return: list's size
 */


size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}


/**
 * get_node_index - Used to get node index
 * @node: Nodes's pointer
 * @head: List's head pointer
 * Return: Index of a node is retured i.e -1
 */


ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t b = 0;

	while (head)
	{
		if (head == node)
			return (b);
		head = head->next;
		b++;
	}
	return (-1);
}


/**
 * node_starts_with - This returns node of string that starts with a prefix
 * @prefix: matched str
 * @node: List head pointer
 * @c: Next char after prefix
 * Return: Node match or null
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


