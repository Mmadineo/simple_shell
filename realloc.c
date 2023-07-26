#include "shell.h"
/**
* _memset – fills allocated  memory with a constant byte
* @s: the pointer to the allocated memory.
* @b: the byte to fill.
* @n: the size  to fill the memory.
* Return: pointer to the memory allocated.
*/
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}
/**
* ffree – Its clears a string of strings
* @pp: The string of strings
*/
void ffree(char **pp)
{
char **a = pp;
if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}
/**
* _realloc - reallocates memory to a different block.
* @ptr: pointer to previous memory block.
* @old_size: byte size of previous block
* @new_size: size of new block
* Return: pointer to the new block.
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}

