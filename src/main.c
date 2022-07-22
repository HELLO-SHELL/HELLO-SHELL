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
    init_minishell(minishell);
    system("leaks minishell");
    return(0);
}
