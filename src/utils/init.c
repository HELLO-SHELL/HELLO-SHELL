#include "../../include/minishell.h"

void    init_minishell(t_node *minishell)
{
    char *input;

    while(1)
    {
        input = readline("HELLO-SHELL-0.0$ ");
       
        if (input)
        {
            if (is_same_string(input, ENV))
                ft_env(minishell->env_list);
            else
            {
                write(2,"HELLO-SHELL: ", 13);
                write(2, input, ft_strlen(input));
                write(2, ": command not found\n", 21);
            }
        }
        else
            break ;
        add_history(input);
        free(input);
    }
}