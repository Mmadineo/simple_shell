#include "shell.h"
/**
* interactive – A function that checks if shell
* is in interactive mode or not.
* @info: structure with arguments
* Return: 1 when on interactive and  0 when not.
*/
int interactive(info_t *info)
{
return (isatty(STDIN_FILENO) && info->readfd <= 2);
}
/**
* is_delim - checks for a  delimeter in a char
* @c: The char to check
* @delim: The delim
* Return: 1 on success and0 on fail
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

