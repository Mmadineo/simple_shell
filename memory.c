#include "shell.h"
/**
* bfree – clears a pointer and NULLs the address.
* @ptr: pointer to clear.
* Return: 1 on success and 0 on fail.
*/
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}

