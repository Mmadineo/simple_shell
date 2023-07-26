#include "shell.h"
/**
* _strcpy - copies a string
* @dest: the destination of the string.
* @src: the source
* Return: destination pointer.
*
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}
*/
char *_strcpy(char *dest, char *src)
{
    char *ret = dest;
    if (dest != src && src)
        while ((*dest++ = *src++))
            ;
    return ret;
}
/**
* _strdup - duplicates a string
* @str: string to duplicate
* Return: duplicated str ptr.
*/
char *_strdup(const char *str)
{
    int length = 0;
    char *ret;
    int i;
    if (str == NULL)
        return (NULL);
    while (str[length])
        length++;
    ret = malloc(sizeof(char) * (length + 1));
    if (!ret)
        return (NULL);
    for (i = 0; i < length; i++)
        ret[i] = str[i];
    ret[length] = '\0';
    return (ret);
}
/**
* _puts - prints a string
* @str: string to be printed
* Return: Nothing
*/
void _puts(char *str)
{
int i;
    if (!str)
        return;
    for (i = 0; str[i] != '\0'; i++)
        _putchar(str[i]);
}
/**
* _putchar – prints a  the char to stdout
* @c: The char
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
/
int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
*/
int _putchar(char c) {

  static int i = 0;
  static char buf[WRITE_BUF_SIZE];

  if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) {
    write(1, buf, i);
    i = 0;
  }

  if (c != BUF_FLUSH) {
    buf[i] = c;
    i++;
  }

  return 1;

}
