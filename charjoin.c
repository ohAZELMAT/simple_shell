#include "shell.h"
/**
 * *charjoin - a helper function
 * @str: string
 * @c: c
 * Return: number
 */
char    *charjoin(char *str, char c)
{
int             i;
char    *ptr;

i = 0;
ptr = malloc(strlen(str) + 2);
if (!ptr)
return (NULL);
if (str)
{
while (str[i])
{
ptr[i] = str[i];
i++;
}
}
ptr[i] = c;
ptr[i + 1] = '\0';
return (ptr);
}
