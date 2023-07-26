#include "shell.h"
/**
* get_history_file - gets the history file
* @info: struct with arguments.
* Return: history file
*/
char *get_history_file(info_t *info)
{
char *buf, *dir;
dir = _getenv(info, "HOME=");
if (!dir)
return (NULL);
buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
if (!buf)
return (NULL);
buf[0] = 0;
_strcpy(buf, dir);
_strcat(buf, "/");
_strcat(buf, HIST_FILE);
return (buf);
}
/**
* write_history - creates a history file or makes changes to an existing file.
* @info: structure with arguments
* Return: 1 on success and  -1 on fail.
*/

/**
* read_history - reads history files
* @info: structure with arguments.
*
* Return: histcount on success 0 on fail.
*/

/**
* build_history_list - adds entry to a history linked list
* @info: Structure with arguments.
* @buf: buffer.
* @linecount: the history linecount, histcount
* Return: 0
*/
int build_history_list(info_t *info, char *buf, int linecount)
{
list_t *node = NULL;
if (info->history)
node = info->history;
add_node_end(&node, buf, linecount);
if (!info->history)
info->history = node;
return (0);
}
/**
* renumber_history – re index history linked list after changes
* @info: Structure with arguments.
* Return: histcount
*/
int renumber_history(info_t *info)
{
list_t *node = info->history;
int i = 0;
while (node)
{
node->num = i++;
node = node->next;
}
return (info->histcount = i);
}

