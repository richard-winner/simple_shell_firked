#include "shell.h"
/**
 * _myhistory - the function here displays the history list
 * one command by line, preceded with line numbers, starting at 0.
 * @info: the structure contains potential arguments
 *  Used to maintain constant function prototype.
 *  Return: Always return 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 * unset_alias - the function here sets an alias to string
 * @info: the parameter structure
 * @str: this is the string alias
 * Return: Always return 0 on success, else 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *p, k;
	int deret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	k = *p;
	*p = 0;
	deret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = k;
	return (deret);
}
/**
 * set_alias - this function here sets alias to the string
 * @info: the parameter structure
 * @str: this is the string alias
 * Return: Always return 0 on success, else 1 on error
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
 * print_alias - here function prints an alias the string
 * @node: this rep the alias node
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
		return (0);
	}
	return (1);
}
/**
 * _myalias - function mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments
 * Used to maintain constant function prototype.
 *  Return: Always return 0
 */
int _myalias(info_t *info)
{
	int w = 0;
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
	for (w = 1; info->argv[w]; w++)
	{
		p = _strchr(info->argv[w], '=');
		if (p)
			set_alias(info, info->argv[w]);
		else
			print_alias(node_starts_with(info->alias, info->argv[w], '='));
	}

	return (0);
}
