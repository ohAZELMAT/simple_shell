#include "shell.h"

/**
 * *get_command_path - gets the commande path
 * @command: the command
 * @envp : the envirenement
 * Return: the path
 */

char    *get_command_path(char *command, char **envp)
{
char    *path;

path = NULL;
if (access(command, F_OK) == 0)
path = strdup(command);
else
{
path = help_get_command_path(command, envp);
if (access(path, F_OK) != 0)
{
free(path);
return (strdup(""));
}
}
return (path);
}
/**
 * execute_command - it executes the command
 * @vector: the inpute
 * @envp: the envirenement
 * Return: nothing
 */
void     execute_command(char **vector, char **envp)
{
char *path;

path = get_command_path(vector[0], envp);
if (!strcmp(path, ""))
{
write(2, *vector, strlen(*vector));
write(2, ": No such file or directory\n", 28);
free_split(vector);
free(path);
return;
}
if (fork_wrapper() == 0)
{
if (execve(path, vector, envp) < 0)
{
perror(*vector);
exit(127);
}
}
wait(NULL);
free_split(vector);
free(path);

}
/**
 * to_lower -makes the string lower case
 * @str: the giving string
 *
 * Return: nothing
 */
void    to_lower(char *str)
{
int     i;

i = 0;
while (str[i])
{
if (str[i] >= 65 && str[i] <= 90)
str[i] += 32;
i++;
}
}
