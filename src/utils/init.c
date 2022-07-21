#include "../../include/minishell.h"

void    init_minishell(void)
{
    char *input;

    while(1)
    {
        input = readline("HELLO-SHELL-0.0$ ");
        if (input)
            printf("%s\n", input);
        else
            break ;
        add_history(input);
        free(input);
    }
}