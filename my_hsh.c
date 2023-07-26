#include "shell.h"

/**
 * prompt_user - Display the prompt for the user.
    Return:Nothing.
 */
void prompt_user()
{
    _puts("$ ");
    _eputchar(BUF_FLUSH);
}

/**
 * process_input - Process the user input.
 * @info: The info_t structure with arguments.
 * @av: The argument vector.
 * Return: The return value from the prev exec cmd.
 */
int process_input(info_t *info, char **av)
{
    ssize_t r = 0;
    int builtin_ret = 0;

    while (r != -1 && builtin_ret != -2)
    {
        clear_info(info);

        if (interactive(info))
            prompt_user();

        r = get_input(info);

        if (r != -1)
        {
            set_info(info, av);
            builtin_ret = find_builtin(info);
            if (builtin_ret == -1)
                find_cmd(info);
        }
        else if (interactive(info))
            _putchar('\n');

        free_info(info, 0);
    }

    write_history(info);
    free_info(info, 1);

    if (!interactive(info) && info->status)
        exit(info->status);

    if (builtin_ret == -2)
    {
        if (info->err_num == -1)
            exit(info->status);
        exit(info->err_num);
    }

    return builtin_ret;
}

/**
 * hsh - The main shell function.
 * @info: The info_t structure with arguments.
 * @av: The argument vector.
 * Return: The return value from the prev exec cmd.
 */
int hsh(info_t *info, char **av)
{
    return process_input(info, av);
}

