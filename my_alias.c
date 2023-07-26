#include "shell.h"
/**
* _myalias – works like the built in alias function.
* @info: struc with arguments.
* Return: 0 on success.
*/
int _myalias(info_t *info) 
{
  if (is_listing_mode(info)) {
    list_aliases(info);
    return 0; 
  }
  
  alias_operation_mode(info);
  return 0; 
}
/**
* is_listing_mode – checks if listing_mode is true.
* @info: struct with arguments.
* Return: 1 on success.
*/
int is_listing_mode(info_t *info) 
{
  return info->argc == 1; 
}
/**
* list_aliases – lists all aliases.
* @info: struct with arguments.
* Return: nothing.
*/
void list_aliases(info_t *info) 
{
  list_t *node = info->alias;
  while (node) {
    print_alias(node);
    node = node->next; 
  }
}  
/**
* alias_operation_mode – processes the aliases.
* @info: structure with arguments.
* Return:nothing.
*/
void alias_operation_mode(info_t *info) 
{
  int i;
  char *p = NULL;
  for (i = 1; info->argv[i]; i++) {
    p = _strchr(info->argv[i], '=');
    if (p)
      set_alias(info, info->argv[i]);
    else
      print_alias(node_starts_with(info->alias, info->argv[i], '='));
  } 
}

