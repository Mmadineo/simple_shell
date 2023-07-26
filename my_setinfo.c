#include "shell.h"
/**
* set_info – sets info of the current cmd.
* @info: The struct with arguments.
* @av: Argument vector.
* Return: Nothing.
*/
void set_info(info_t *info, char **av)
{
    info->fname = av[0];
    if (info->arg)
    {
        info->argv = tokenize_argument(info->arg);
        info->argc = count_args(info->argv);
        replace_alias(info);
        replace_vars(info);
    }
}
/**
* tokenize_argument – tokenizes functions.
* @arg: The argument.
* Return: argument vector.
*/
char **tokenize_argument(char *arg)
{
    char **argv = strtow(arg, " \t");
    if (!argv)
    {
        argv = malloc(sizeof(char *) * 2);
        if (argv)
        {
            argv[0] = _strdup(arg);
            argv[1] = NULL;
        }
    }
    return argv;
}
/**
* count_args – counts number of arguments.
* @argv: argument vector.
* Return: i.
*/
int count_args(char **argv)
{
    int i;
    for (i = 0; argv && argv[i]; i++)
        ;
    return i;
}

