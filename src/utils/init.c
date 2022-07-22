#include "../../include/minishell.h"

void    init_minishell(t_node *minishell)
{
    char *input;

    while(1)
    {
        input = readline("HELLO-SHELL-0.0$ ");
        if (is_same_string(input, ENV))
            ft_env(minishell->env_list);
        else if (input)
            printf("%s\n", input);
        else
            break ;
        add_history(input);
        free(input);
    }
}