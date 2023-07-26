#include "shell.h"
/**
* list_len – A  function that determines the length of linked list
* @h: The first node pointer.
* Return: size of list
*/
size_t list_len(const list_t *h)
{
const list_t *current;
    size_t i = 0;
    for (current = h; current != NULL; current = current->next)
    {
        i++;
    }
    return i;
}

/**
* list_to_strings -A function that returns an array of strings of the list->str
* @head: first node ptr.
* Return: array of strings
*/
char **list_to_strings(list_t *head)
{
    size_t i = list_len(head);
    size_t j;
    list_t *node;
    char **strs = malloc(sizeof(char *) * (i + 1));
    if (!strs)
        return (NULL);
    node = head;
    for (i = 0; node; node = node->next, i++)
    {
        strs[i] = _strdup(node->str);
        if (!strs[i])
        {
            for (j = 0; j < i; j++)
                free(strs[j]);
            free(strs);
            return (NULL);
        }
    }
    strs[i] = NULL;
    return (strs);
}

/**
* print_list – shows elements of a list_t linked list
* @h: first node ptr.
* Return: size of list
*/
size_t print_list(const list_t *h)
{
size_t i = 0;
while (h)
{
_puts(convert_number(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
/**
* node_starts_with - returns node whose string starts with prefix
* @node: node ptr.
* @prefix: The prefix to search.
* @c: The next char to search.
* Return: The match node or null
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
char *p = NULL;
while (node)
{
p = starts_with(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
/**
* get_node_index - gets the index of a node
* @head: First node pointer.
* @node: The node pointer.
* Return:  -1 for index of node.
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;
while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}

