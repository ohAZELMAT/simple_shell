#include "shell.h"
/**
 * *filling - a hepler function
 * @s1: string
 * @s2: string
 * @ptr: pointer
 * Return: number
 */
static char     *filling(char const *s1, char const *s2, char   *ptr)
{
size_t  i;

i = 0;
while (i < strlen(s1))
{
ptr[i] = s1[i];
i++;
}
i = 0;
while (i < strlen(s2))
{
ptr[i + strlen(s1)] = s2[i];
i++;
}
ptr[i + strlen(s1)] = '\0';
return (ptr);
}
/**
 * *strjoin - a helper function
 * @s1: string
 * @s2: string
 *
 * Return: number
 */

char    *strjoin(char const *s1, char const *s2)
{
char    *ptr;

ptr = malloc(strlen(s1) + strlen(s2) + 1);
if (ptr == NULL)
return (NULL);
return (filling(s1, s2, ptr));
}
