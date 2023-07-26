#include "shell.h"
/**
free_list – A function that clears a linked list
@head_ptr: head ptr
Return:Nothing.
*/

void free_list(list_t **head_ptr)
{
list_t *node;
  if (!valid_list(head_ptr))
    return;

  node = *head_ptr;
  while (node) {
    list_t *next_node = node->next;
    free_node(node);
    node = next_node;
  }
  *head_ptr = NULL;
}
/**
valid_list – checks the validity of linked list.
@head_ptr: The head pointer.
Return: true if the ptr in not NULL.
*/
int valid_list(list_t **head_ptr)
{
  return head_ptr != NULL && *head_ptr != NULL;
}
/**
free_node – clears the node in a linked list.
@node:pointer to the node.
Return:Nothing.
*/
void free_node(list_t *node)
{
  free(node->str);
  free(node);
}

