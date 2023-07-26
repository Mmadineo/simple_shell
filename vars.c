#include "shell.h"
/**
* is_chain - test if current char in buffer is a chain delimeter
* @info: struct with arguments.
* @buf: char buffer
* @p: address of current position in buf
* Return: 1 on success and 0 on fail.
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
    size_t j = *p;
    switch (buf[j])
    {
        case '|':
            if (buf[j + 1] == '|')
            {
                buf[j] = 0;
                j++;
                info->cmd_buf_type = CMD_OR;
            }
            break;
        case '&':
            if (buf[j + 1] == '&')
            {
                buf[j] = 0;
                j++;
                info->cmd_buf_type = CMD_AND;
            }
            break;
        case ';':
            buf[j] = 0;
            info->cmd_buf_type = CMD_CHAIN;
            break;
        default:
            return (0);
    }
    *p = j;
    return (1);
}
/**
* check_chain - checks last status if
* it should chain.
* @info: structure with arguments.
* @buf: the char buffer
* @p: address of current position in buf
* @i: starting position in buf
* @len: length of buf
* Return: Void
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
    size_t j = *p;
    switch (info->cmd_buf_type)
    {
        case CMD_AND:
            if (info->status)
            {
                buf[i] = 0;
                j = len;
            }
            break;
        case CMD_OR:
            if (!info->status)
            {
                buf[i] = 0;
                j = len;
            }
            break;
    }
    *p = j;
}
/**
* replace_alias – substitutes aliases of tokenized string
* @info: struct with arguments.
* Return: 1 on success and 0 on fail.
*/
int replace_alias(info_t *info)
{
    int i = 0;
    list_t *node;
    char *p;

    while (i < 10)
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
        i++;
    }
    return (1);
}
/**
* replace_vars – substitutes tokenized string
* @info: struct with arguments.
* Return: 1 on success and 0 on fail.
*/
int replace_vars(info_t *info)
{
    int i = 0;
    list_t *node;
    for (i = 0; info->argv[i]; i++)
    {
        if (info->argv[i][0] != '$' || !info->argv[i][1])
            continue;
        switch (info->argv[i][1])
        {
            case '?':
                if (!_strcmp(info->argv[i], "$?"))
                {
                    replace_string(&(info->argv[i]),
                        _strdup(convert_number(info->status, 10, 0)));
                }
                break;
            case '$':
                if (!_strcmp(info->argv[i], "$$"))
                {
                    replace_string(&(info->argv[i]),
                        _strdup(convert_number(getpid(), 10, 0)));
                }
                break;
            default:
                node = node_starts_with(info->env, &info->argv[i][1], '=');
                if (node)
                {
                    replace_string(&(info->argv[i]),
                        _strdup(_strchr(node->str, '=') + 1));
                }
                else
                {
                    replace_string(&info->argv[i], _strdup(""));
                }
        }
    }
    return (0);
}

/**
* replace_string - replaces strings
* @old: address to the old string
* @new: The new string
* Return: 1 on success and 0 on fail.
*/
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}

