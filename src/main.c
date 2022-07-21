#include "../include/minishell.h"

void    split_env(t_env *env_node, char **env, int i)
{
    char    *key;
    char    *delimiter;
    char    *value;

    delimiter = ft_strchr(env[i], '=');
    *delimiter = 0;
    key = env[i];
    value = delimiter + 1;
    env_node->key = ft_strdup(key);
    env_node->value = ft_strdup(value);
}

void    env_linked_list(t_node *minishell, char **env)
{
    t_env   *env_node;
    int     i;

    minishell->env_list = (t_list *)malloc(sizeof(t_list));
    if (minishell->env_list == 0)
        exit(1);
    minishell->env_list = 0;
    i = 0;
    while (env[i])
    {
        env_node = (t_env *)malloc(sizeof(t_env));
        if (env_node == 0)
            exit(1);
        split_env(env_node, env, i);
        ft_lstadd_back(&(minishell->env_list), ft_lstnew(env_node));
        i++;
    }
}

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

int main(int ac, char **av, char **env)
{
    (void) ac;
    (void) av;
    t_node  *minishell;

    minishell = (t_node *)malloc(sizeof(t_node));
    if (minishell == 0)
        return (0);
    env_linked_list(minishell, env);
    init_minishell();

    // t_list  *curr;    
    // curr = minishell->env_list;
    // while (curr->next)
    // {
    //     printf("key = %s, value = %s\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
    //     curr = curr->next;
    // }
    system("leaks minishell");
    return(0);
}
