#include "shell.h"


/**
 * dup_chars - Chr duplication
 * @start: index start
 * @stop: index stop
 * @pathstr: str path
 * Return: pointer to new buffer
 */


char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int a = 0, j = 0;

	for (j = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buf[j++] = pathstr[a];
	buf[j] = 0;
	return (buf);
}

/**
 * find_path - Find command in PATH str
 * @info: Struct info
 * @pathstr: Str path
 * @cmd: command to search
 * Return: Retuen Path of cmd if found
 */

char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int g = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[g] || pathstr[g] == ':')
		{
			path = dup_chars(pathstr, curr_pos, g);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[g])
				break;
			curr_pos = g;
		}
		g++;
	}
	return (NULL);
}

/**
 * is_cmd - Checks if a file is exe comd
 * @path: file path
 * @info: Struct info
 * Return: 1 if true, 0 otherwise
 */


int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
