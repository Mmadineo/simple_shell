#include "shell.h"
/**
**_strncpy - copies a string
*@dest: destination of the copied string.
*@src: source of the copied string
*@n: Number of characters to be copied.
*Return:  concatenated string.
*/	
char *_strncpy(char *dest, char *src, int n)
{
int i;
for (i = 0; i < n && src[i] != '\0'; i++)
{
dest[i] = src[i];
}
for (; i < n; i++)
{
dest[i] = '\0';
}
return (dest);
}
/**
**_strncat - concatenates two strings
*@dest: string 1
*@src: string2
*@n: byte size to be used.
*Return: concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
char *p = dest;
while (*p)
{
p++;
}
while (n-- > 0 && *src)
{
*p++ = *src++;
}
*p = '\0';
return (dest);
}
/**
**_strchr – finds a char in a string
*@s: the string to be looked at.
*@c: the char we a looking for.
*Return: a pointer to the char.
*/
char *_strchr(char *s, char c)
{
while (*s && *s != c)
{
s++;
}
return (*s == c ? s : NULL);
}

