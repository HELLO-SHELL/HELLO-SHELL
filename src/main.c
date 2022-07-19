#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    
    char *str;
    while(1)
    {
        str = readline("HELLO-SHELL-0.0$ ");
        if (str)
            printf("%s\n", str);
        else
            break ;
        add_history(str);
        free(str);
    }
    system("leaks minishell");
    return(0);
}