#include "../../../include/minishell.h"

void    split_env(t_env *env_node, char **env, int i)
{
    char    *key;
    char    *delimiter;
    char    *value;

    delimiter = ft_strchr(env[i], '=');
    *delimiter = '\0';
    key = env[i];
    value = delimiter + 1;
    env_node->key = ft_strdup(key);
    env_node->value = ft_strdup(value);
}

void    env_linked_list(t_minishell *minishell, char **env)
{
    t_env   *env_node;
    int     i;

    minishell->env_list = (t_list *)malloc(sizeof(t_list));
    if (minishell->env_list == NULL)
        exit(1);
    minishell->env_list = NULL;
    i = 0;
    while (env[i])
    {
        env_node = (t_env *)malloc(sizeof(t_env));
        if (env_node == NULL)
            exit(1);
        split_env(env_node, env, i);
        ft_lstadd_back(&(minishell->env_list), ft_lstnew(env_node));
        i++;
    }
}