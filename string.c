#include "shell.h"
/**
* _strlen – A function that gets  the length of a string
* @s: The string to get its length
* Return: The length of the string
*/
int _strlen(char *s)
{
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

/**
* _strcmp -  compares two strings.
* @s1: string 1
* @s2: string2
* Return: 0 when s1 is equal to s2,
* -1 when s1 is less than s2,
* 1 when s1 is greater than s2.
*/
int _strcmp(char *s1, char *s2)
{
    int i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        if (s1[i] != s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    if (s1[i] == s2[i])
        return (0);
    else
        return (s1[i] < s2[i] ? -1 : 1);
}

/**
* starts_with – The function checks if needle 
* starts with haystack
* @haystack: string to search
* @needle: the substring to find
* Return: address of next char of haystack or NULL
*/
char *starts_with(const char *haystack, const char *needle)
{
    while (*needle && *haystack)
    {
        if (*needle != *haystack)
            return NULL;
        needle++;
        haystack++;
    }
    if (*needle)
        return NULL;
    return (char *)haystack;
}
/**
* _strcat -  A function that concatenates two strings
* @dest: destination
* @src: The source
* Return: A pointer to where the string is concated.
*/
char *_strcat(char *dest, char *src)
{
    char *ret = dest;
    while (*dest)
        dest++;
    while ((*dest++ = *src++))
        ;
    return ret;
}
