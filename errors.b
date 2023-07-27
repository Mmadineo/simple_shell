#include "shell.h"
/**
* _eputs - prints a string.
* @str: the string to print.
* Return: Nothing
*/
void _eputs(char *str)
{
int i = 0;
if (!str)
return;
for (; str[i] != '\0'; i++)
_eputchar(str[i]);
}
/**
* _eputchar – prints a char to stderr
* @c: The char
* Return: On success 1 and -1 on fail.
*/
int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
if (write(2, buf, i) == -1)
return (-1);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
* _putfd – prints character to the file descriptor.
* @c: The character to be printed
* @fd: The file descriptor.
* Return: 1 on success and -1 on fail.
*/
int _putfd(char c, int fd)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
if (write(fd, buf, i) == -1)
return (-1);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
* _putsfd - prints an input string to the file descriptor.
* @str: The string to be printed.
* @fd: The file descriptor.
* Return: Number of character printed.
*/
int _putsfd(char *str, int fd)
{
int i = 0;
if (!str)
return (0);
for (; *str; str++)
i += _putfd(*str, fd);
return (i);
}

