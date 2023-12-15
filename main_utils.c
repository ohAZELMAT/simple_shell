#include "shell.h"

/**
 * free_split - a hepler funtions
 * @tmp : temporary holder
 * Return: nothing
 */

void    free_split(char **tmp)
{
int     i;

i = 0;
while (tmp[i])
{
free(tmp[i]);
i++;
}
free(tmp);
}
/**
 * fork_wrapper - a helper function
 *
 * Return: number
 */
int     fork_wrapper(void)
{
int     pid;

pid = fork();
if (pid < 0)
exit(EXIT_FAILURE);
return (pid);
}
/**
 * strlen_double - a helper function
 * @str : double pionter
 * Return: number
 */

int     strlen_double(char **str)
{
int     i;

i = 0;
if (!*str)
return (0);
while (str[i])
i++;
return (i);
}
/**
 * **find_outer_path - a helper function
 * @envp: envirenemt
 * Return: number
 */
char    **find_outer_path(char **envp)
{
int     i;

i = 0;
if (!envp)
return (NULL);
while (envp[i])
{
if (!strncmp(envp[i], "PATH", 4))
break;
i++;
}
if (i == strlen_double(envp))
return (NULL);
return (complex_split(envp[i], "PATH=:"));
}
/**
 * *help_get_command_path - a hepler function
 * @command: a command
 * @envp: envirenemrnt
 * Return: number
 */
char    *help_get_command_path(char *command, char **envp)
{
char    **outer_path;
char    *path;
char    *tmp;
int     i;

i = 0;
outer_path = find_outer_path(envp);
if (outer_path == NULL)
return (NULL);
while (outer_path[i])
{
tmp = charjoin(outer_path[i], '/');
path = strjoin(tmp, command);
free(tmp);
if (access(path, F_OK) == 0)
break;
if (outer_path[i + 1] != NULL)
free(path);
i++;
}
free_split(outer_path);
return (path);
}
