#include "shell.h"
/**
* _myhistory – A function that shows  the history list.
* @info: The structure with arguments.
* Return: 0
*/
int _myhistory(info_t *info)
{
list_t *node = info->history;
int i = 0;
while (node)
{
_puts(convert_number(i, 10, 0));
_putchar(' ');
_putchar(' ');
_puts(node->str);
_putchar('\n');
node = node->next;
i++;
}
return (0);
}
/**
* unset_alias – A function that sets alias to string
* @info: The structure with arguments
* @str: string alias
* Return: 0 on success and 1 on fail
*/
int unset_alias(info_t *info, char *str)
{
char *p, c;
int ret;
p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
ret = delete_node_at_index(&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
*p = c;
return (ret);
}
/**
* set_alias - adds alias to a string
* @info: structure with arguments
* @str: the string.
* Return: 0 on success and1 on fail
*/
int set_alias(info_t *info, char *str)
{
char *p = _strchr(str, '=');
if (!p || !*++p)
return (unset_alias(info, str));
unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
* print_alias – displays the alias
* @node: the node.
* Return: 0 on success and 1 on fail.
*/
int print_alias(list_t *node)
{
char *p, *a;

if (!node)
return (1);
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}

