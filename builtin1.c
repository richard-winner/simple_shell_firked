#include "shell.h"

/**
 * set_alias - the function here sets alias to string
 * @str: this is the string alias
 * @info: tis is a parameter struct
 * Return: Always return 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - this function prints an alias string
 * @node: this is the alias node
 * Return: Always return 0 on success, else 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
		_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		retturn (0);
	}
	return (1);
}

/**
 * _myhistory - the function displays the history list, one command by line
 * preceded with line numbers, starting at 0
 * @info: Structure containing potential arguments
 * Used to maintain
 * constant function prototype
 *  Return: Always return 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - the function here sets alias to string
 * @info: this is a parameter struct
 * @str: this is the string alias
 * Return: Always return 0 on success, else 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, q;
	int rett;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	q = *p;
	*p = 0;
	rett = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = q;
	return (rett);
}

/**
 * _myalias - the function mimics the alias builtin
 * @info: this is the structure containing potential arguments
 * this is used to maintain
 * constant function prototype.
 * Return: Always return 0
 */
int _myalias(info_t *info)
{
	int v = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (v = 1; info->argv[v]; v++)
	{
		p = _strchr(info->argv[v], '=');
		if (p)
			set_alias(info, info->argv[v]);
		else
			print_alias(node_starts_with(info->alias, info->argv[v], '='));
	}

	return (0);
}
