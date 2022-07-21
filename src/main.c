#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    t_node  *minishell;

    minishell = (t_node *)malloc(sizeof(t_node));
    if (minishell == 0)
        return (0);
    env_linked_list(minishell, env);
    // t_list  *curr;    
    // curr = minishell->env_list;
    // while (curr->next)
    // {
    //     printf("key = %s, value = %s\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
    //     curr = curr->next;
    // }
    init_minishell();
    system("leaks minishell");
    return(0);
}
