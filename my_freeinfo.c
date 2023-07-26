#include "shell.h"
void free_environ(info_t *info);
void free_info(info_t *info, int all)
{
    free_argv(info);
    info->path = NULL;
    if (all)
    {
        free_arg(info);
        free_env(info);
        free_history(info);
        free_alias(info);
        free_environ(info);
        free_cmd_buf(info);
        close_read_fd(info);
        _putchar(BUF_FLUSH);
    }
}
void free_argv(info_t *info)
{
    ffree(info->argv);
    info->argv = NULL;
}

void free_arg(info_t *info)
{
    if (!info->cmd_buf)
        free(info->arg);
}

void free_env(info_t *info)
{
    if (info->env)
        free_list(&(info->env));
}

void free_history(info_t *info)
{
    if (info->history)
        free_list(&(info->history));
}

void free_alias(info_t *info)
{
    if (info->alias)
        free_list(&(info->alias));
}

void free_environ(info_t *info)
{
    ffree(info->environ);
    info->environ = NULL;
}

void free_cmd_buf(info_t *info)
{
    bfree((void **)info->cmd_buf);
}

void close_read_fd(info_t *info)
{
    if (info->readfd > 2)
        close(info->readfd);
}

