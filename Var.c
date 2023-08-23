include "shell.h"

/**
 * is_chain - This test if the current character in buffer is chain delimeter
 * @p: This shows the address of current position in a buffer
 * @buf: This is the character of a buffer
 * @info: It shows the structs parameter
 * Return: This returns 1 if chain delimeter, otherwise 0
 */

int is_chain(info_t *info, char *buf, size_t *p)
{
        size_t q = *p;

        if (buf[q] == '|' && buf[q + 1] == '|')
        {
                buf[q] = 0;
                q++;
                info->cmd_buf_type = CMD_OR;
        }
        else if (buf[q] == '&' && buf[q + 1] == '&')
        {
                buf[q] = 0;
                q++;
                info->cmd_buf_type = CMD_AND;
        }
        else if (buf[q] == ';')
        {
                buf[q] = 0;
                info->cmd_buf_type = CMD_CHAIN;
        }
        else
                return (0);
        *p = q;
		return (1);
}

/**
 * check_chain: We need to assess whether we should continue the sequence of
 * actions based on the most recent status update
 * @buf: This is the buffer character
 * @info: This is the struct parameter
 * @len: Buffer length
 * @i: This is where the buffer starts
 * @p: The buffer current position with address
 * Return: This returns void
 */

void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
        size_t q = *p;

        if (info->cmd_buf_type == CMD_AND)
        {
                if (info->status)
                {
                        buf[i] = 0;
                        q = len;
                }
        }
        if (info->cmd_buf_type == CMD_OR)
        {
                if (!info->status)
                {
                        buf[i] = 0;
                        q = len;
                }
        }

        *p = q;
}

/**
 * replace_alias - This replaces aliases in tokenized str
 * @info: This is the struct parameter
 * Return: Replace 1, otherwise 0
 */

int replace_alias(info_t *info)
{
        int i;
        list_t *node;
        char *p;

        for (i = 0; i < 10; i++)
        {
                node = node_starts_with(info->alias, info->argv[0], '=');
                if (!node)
                        return (0);
                free(info->argv[0]);
                p = _strchr(node->str, '=');
                if (!p)
                        return (0);
                p = _strdup(p + 1);
                if (!p)
                        return (0);
                info->argv[0] = p;
        }
        return (1);
}

/**
 * replace_vars - This replaces vars in tokenized str
 * @info: This is the struct parameter
 * Return: Replace 1, otherwise 0
 */

int replace_vars(info_t *info)
{
        int i = 0; /* setting i to 0*/
        list_t *node;

        for (i = 0; info->argv[i]; i++)
        {
                if (info->argv[i][0] != '$' || !info->argv[i][1])
                        continue;

                if (!_strcmp(info->argv[i], "$?"))
                {
                        replace_string(&(info->argv[i]),
                                        _strdup(convert_number(info->status, 10, 0)));
                        continue;
                }
                if (!_strcmp(info->argv[i], "$$"))
                {
                        replace_string(&(info->argv[i]),
                                        _strdup(convert_number(getpid(), 10, 0)));
                        continue;
                }
                node = node_starts_with(info->env, &info->argv[i][1], '=');
                if (node)
                {
                        replace_string(&(info->argv[i]),
                                        _strdup(_strchr(node->str, '=') + 1));
                        continue;
                }
                replace_string(&info->argv[i], _strdup(""));

        }
		return (0);
}

/**
 * replace_string - Str replacement
 * @new: New Str
 * @old: Strs old address
 * Return: Replace 1, otherwise 0
 */

int replace_string(char **old, char *new)
{
        free(*old);
        *old = new;
        return (1);
}


