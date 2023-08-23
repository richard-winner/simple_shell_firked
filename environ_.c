#include "shell.h"

/**
 * _myenv - the function here prints the current environment
 * @info: the structure containing potential arguments
 * Used to maintain constant function prototype.
 * Return: Always return 0
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}
/**
 * _getenv - this function also gets the value of an environ variable
 * @info: the structure containing potential arguments
 * Used to maintain
 * @name: the env var name
 * Return: this is the value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
/**
 * _mysetenv - this is the function initialize a new environmen
 variable,
 * or modify an existing one
 * @info: this is structure containing potential arguments
 *  constant function prototype
 *  Return: Always return 0
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - the function removes an environment variable
 * @info: this is structure containing potential arguments
 * constant function prototype
 * Return: Always return 0
 */
int _myunsetenv(info_t *info)
{
	int v;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (v = 1; v <= info->argc; v++)
		_unsetenv(info, info->argv[v]);

	return (0);
}

/**
 * populate_env_list - the function populates env linked list
 * @info: this is the structure containing potential argument
 * constant function prototype
 * Return: Always return 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t v;

	for (v = 0; environ[v]; v++)
		add_node_end(&node, environ[v], 0);
	info->env = node;
	return (0);
}
