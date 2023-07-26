#include "shell.h"
/**
* clear_info – clears the info_t structure.
* @info: Address to the structure. 
*/
void clear_info(info_t *info)
{
info->arg = NULL;
info->argv = NULL;
info->path = NULL;
info->argc = 0;
}
/**
* set_info – sets the info_t structure.
* @info: Address to the structure.
* @av: argument.
*/

/**
* free_info – clears the  info_t struct fields
* @info: The structures address
* @all: when true it clears all fields.
*/

