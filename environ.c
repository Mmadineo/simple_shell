#include "shell.h"
/**
* _myenv – displays the current environment
* @info: Structure with arguments.
* Return: 0
*/
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}
/**
* _getenv – Fetches values from the env
* @info: Structure with arguments
* @name: var name.
* Return: value
*/
char *_getenv(info_t *info, const char *name)
{
list_t *node;
for (node = info->env; node; node = node->next)
{
char *p = starts_with(node->str, name);
if (p && *p)
return (p);
}
return (NULL);
}
/**
* _mysetenv – A function that sets a new environment or
* changes an existing one.
* @info: Structure with arguments.
* Return: 0
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguments\n");
return (1);
}
return (_setenv(info, info->argv[1], info->argv[2]) == 0);
}
/**
* _myunsetenv - deletes environment variable
* @info: Structure with arguments.
* Return: 0
*/
int _myunsetenv(info_t *info)
{
int i;
if (info->argc == 1)
{
_eputs("Too few arguements.\n");
return (1);
}
for (i = 1; i <= info->argc; i++)
_unsetenv(info, info->argv[i]);
return (0);
}
/**
* populate_env_list – loads the env linked list
* @info: Structure with arguments.
* Return: 0
*/
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;
for (i = 0; environ[i]; i++)
add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}

