#include "shell.h"

/**
 * input_buf - function here buffers chained commands
 * @info: the parameter struct
 * @buf: the address of buffer
 * @len: the address of len var
 * Return:return bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t w = 0;
	size_t len_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		w = getline(buf, &len_p, stdin);
#else
		w = _getline(info, buf, &len_p);
#endif
		if (w > 0)
		{
			if ((*buf)[w - 1] == '\n')
			{
				(*buf)[w - 1] = '\0';
				w--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = w;
				info->cmd_buf = buf;
			}
		}
	}
	return (w);
}

/**
 * get_input - the function gets a line minus the newline
 * @info: the parameter struct
 * Return: return bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t i, j, len;
	ssize_t w = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	w = input_buf(info, &buf, &len);
	if (w == -1)
		return (-1);
	if (len)
	{
		j = i;
		p = buf + i;

		check_chain(info, buf, &j, i, len);
		while (j < len)
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= len)
		{
			i = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p;
		return (_strlen(p));
	}

	*buf_p = buf;
	return (w);
}

/**
 * read_buf - this function here reads a buffer
 * @info: the parameter struct
 * @buf: the buffer
 * @i: return size
 * Return: return w
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t w = 0;

	if (*i)
		return (0);
	w = read(info->readfd, buf, READ_BUF_SIZE);
	if (w >= 0)
		*i = w;
	return (w);
}

/**
 * _getline - function gets the next line of input from STDIN
 * @info: the parameter struct
 * @ptr: the address of pointer to buffer, preallocated or NULL
 * @length: the size of preallocated ptr buffer if not NULL
 * Return: return s
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t w = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	w = read_buf(info, buf, &len);
	if (w == -1 || (w == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sigintHandler - the function here blocks ctrl-C
 * @sig_num: the signal number
 * Return: should be void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
