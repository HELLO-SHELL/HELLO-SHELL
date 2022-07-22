#include "../../include/minishell.h"

void    init_minishell(t_node *minishell)
{
    char *input;

    while(1)
    {
        input = readline("HELLO-SHELL-0.0$ ");
        if (!(ft_strncmp(input, ENV, ft_strlen(input))))
        {
            t_list  *curr;    
            curr = minishell->env_list;
            while (curr->next)
            {
                printf("%s=%s\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
                curr = curr->next;
            }
        }
        else if (input)
            printf("%s\n", input);
        else
            break ;
        add_history(input);
        free(input);
    }
}