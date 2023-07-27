#include "shell.h"
/**
* _erratoi - converts string to int.
* @s: The string.
* Return: 0 on success and -1 on fail.
*/
int _erratoi(char *s)
{
unsigned long int result = 0;
if (*s == '+')
s++;
for (; *s; s++)
{
if (*s >= '0' && *s <= '9')
{
result = result * 10 + (*s - '0');
if (result > INT_MAX)
return (-1);
}
else
return (-1);
}
return (result);
}
/**
* print_error - prints error messages
* @info: The structure with arguments.
* Return: 0 on success and -1 on fail.
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}
/**
* print_d – prints a decimal number.
* @input: The input number.
* @fd: the file descriptor.
* Return: number of characters printed
*/
int print_d(int input, int fd)
{
int digit;
int count = 0;
if (input < 0)
{
_putfd('-', fd);
count++;
input = -input;
}
if (input == 0)
{
_putfd('0', fd);
count++;
}
else
{
int temp = input;
int digits = 0;
while (temp > 0)
{
temp /= 10;
digits++;
}
temp = input;
while (digits > 0)
{
int power = 1;
int i = 1;
for (; i < digits; i++)
{
power *= 10;
}
digit = temp / power;
_putfd('0' + digit, fd);
count++;
temp -= digit * power;
digits--;
}
}
return (count);
}
/**
* convert_number – converters a number to a string.
* @num: The number
* @base: The base
* @flags: flags
* Return: string converted from number
*/
char *convert_number(long int num, int base, int flags)
{
static char buffer[50];
char *ptr = &buffer[49];
unsigned long n = (flags & CONVERT_UNSIGNED) ? (unsigned long)num : (num < 0 ? -num : num);
const char *digits = (flags & CONVERT_LOWERCASE) ? "0123456789abcdef" : "0123456789ABCDEF";
*ptr = '\0';
do {
*--ptr = digits[n % base];
n /= base;
} while (n != 0);
if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
*--ptr = '-';
}
return (ptr);
}
/**
* remove_comments – A function that removes comments.
* @buf: The string address.
*Return: 0;
*/
void remove_comments(char *buf)
{
char *p = buf;
while (*p)
{
if (*p == '#' && (p == buf || *(p - 1) == ' '))
{
*p = '\0';
break;
}
p++;
}
}

