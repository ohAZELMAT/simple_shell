#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <readline/readline.h>


void    to_lower(char *str);
void     execute_command(char **vector, char **envp);
char    *get_command_path(char *command, char **envp);
char    *help_get_command_path(char *command, char **envp);
char    **find_outer_path(char **envp);
int     strlen_double(char **str);
char    **split(char *s, char c);
int     fork_wrapper(void);
void    free_split(char **tmp);
char    **complex_split(char *str, char *charset);
char    *charjoin(char *str, char c);
char    *strjoin(char const *s1, char const *s2);

#endif
