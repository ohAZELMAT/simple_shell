#include "shell.h"

static int              count_words(char *str, char *charset);
static int              is_not_sep(char c, char *charset);
/**
 * **complex_split - a helper function
 * @str: string
 * @charset: character
 * Return: number
 */
char    **complex_split(char *str, char *charset)
{
char    **strs;
int             j;
int             i;
int             k;

if (!str || !charset)
return (NULL);
strs = malloc((count_words(str, charset) + 1) * sizeof(char *));
i = 0;
k = 0;
while (str[i] != '\0')
{
if (is_not_sep(str[i], charset))
{
j = i;
while (is_not_sep(str[j], charset) && str[j] != '\0')
j++;
strs[k] = strndup(&str[i], j - i);
k++;
i = --j;
}
i++;
}
strs[k] = 0;
return (strs);
}
/**
 * is_not_sep - a helper function
 * @charset: character
 * @c: character
 * Return: number
 */

static int      is_not_sep(char c, char *charset)
{
int     i;

i = 0;
while (charset[i] != '\0')
{
if (charset[i] == c)
return (0);
i++;
}
return (1);
}
/**
 * count_words - a helper function
 * @str : string
 * @charset: character
 * Return: number
 */
static int      count_words(char *str, char *charset)
{
int             i;
int             count;

count = 0;
i = 0;
while (str[i] != '\0')
{
if (is_not_sep(str[i], charset))
{
while (is_not_sep(str[i], charset) && str[i] != '\0')
i++;
count++;
}
if (str[i] == '\0')
break;
i++;
}
return (count);
}
