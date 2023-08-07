#include "shell.h"
/**
* interactive - returns true if shell is interactive mode
* @info: struct address
*
* Return: 1 if interactive mode, 0 otherwise
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
* is_delim - checks if character is a delimeter
* @c: the char to check
* @delim: the delimeter string
* Return: 1 if true, 0 if false
*/

int is_delim(char c, char *delim)
{
int i = 0;
for (; delim[i] != '\0'; i++)
{
if (delim[i] == c)
{
return (1);
}
}
return (0);
}
/**
* _isalpha – looks for aplphabets
* @c: The input char
* Return: 1 on success and  0 on fail
*/
int _isalpha(int c)
{
return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/**
* _atoi – converts str to an int
* @s: the string.
* Return: 0 on success.
*/
int _atoi(char *s)
{
int result = 0;
int sign = 1;
int i = 0;

while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
{
if (s[i] == '-')
{
sign *= -1;
}
i++;
}
while (s[i] != '\0' && s[i] >= '0' && s[i] <= '9')
{
result = result * 10 + (s[i] - '0');
i++;
}
return (result *sign);
}

