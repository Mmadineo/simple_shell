#include "shell.h"
/**
* write_history – writes to the history file.
* @info: structure with arguments.
* Return: 1 on success and -1 on fail.
*/
int write_history(info_t *info)
{
int fd;
    char *filename = get_history_file(info);
    if (!filename)
        return (-1);

    fd = open_history_file(filename);
    free(filename);
    if (fd == -1)
        return (-1);

    write_history_to_file(info, fd);
    close(fd);
    return (1);
}
/**
* open_history_file – opens the history file.
* @filename: the file.
* Return: file.
*/
int open_history_file(char *filename)
{
    return open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
}
/**
* write_history_to_file – writes history to a file.
* @info: struc with arguments.
* @fd: file descriptor.
* Return:Nothing.
*/
void write_history_to_file(info_t *info, int fd)
{
    list_t *node = NULL;
    for (node = info->history; node; node = node->next)
    {
        _putsfd(node->str, fd);
        _putfd('\n', fd);
    }
    _putfd(BUF_FLUSH, fd);
}

