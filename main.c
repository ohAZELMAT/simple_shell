#include "shell.h"

#define PROMPT "\001\033[1;32m\002hsh$ \001\033[0m\002 "

/**
 * env - the env fontionality
 * @envp: envirenement
 *
 * Return: nothing
 */

void    env(char **envp)
{
int     i;

i = 0;
while (envp[i])
{
i++;
}
}
/**
 * help_main - it is a helper function
 * @input: the input
 * @envp: the envirenement
 *
 * Return: nothing
 */

void    help_main(char *input, char **envp)
{
char **vector;

vector = split(input, ' ');
if (*vector)
{
to_lower(*vector);
if (!strcmp(*vector, "exit"))
{
exit(0);
}
if (!strcmp(*vector, "env"))
{
env(envp);
return;
}
execute_command(vector, envp);
}
}
/**
 * main - the main function
 * @argc: argument count
 * @argv: argument victor
 * @envp: the envirenement
 * Return: integer
 */
int     main(int argc, char **argv, char **envp)
{
char            *input;
size_t          input_size;
int             ret;
(void)argc;
(void)argv;

input_size = 1024;
input = (char *)malloc(input_size *sizeof(char));
if (input == NULL)
{
perror("Unable to allocate buffer");
exit(1);
}
ret = getline(&input, &input_size, stdin);
if (ret == -1)
{
exit(1);
}
while (input)
{
if (*input)
{
if (input[strlen(input) - 1] == '\n')
input[strlen(input) - 1] = '\0';
help_main(input, envp);
}
free(input);
input = (char *)malloc(input_size *sizeof(char));
if (input == NULL)
{
perror("Unable to allocate buffer");
exit(1);
}
ret = getline(&input, &input_size, stdin);
if (ret == -1)
{
exit(1);
}
}
return(0);
}

