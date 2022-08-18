#include "test.h"

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

    i = 0;
    while (env[i])
    {
        env_node = malloc(sizeof(t_env));
        env_node->key = NULL;
        env_node->value = NULL;
        split_env(env_node, env, i);
        ft_lstadd_back(&(minishell->env_list), ft_lstnew(env_node));
        i++;
    }
}

static char	*ft_env_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*temp;

	temp = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2) * sizeof(char));
	if (!temp)
		return (0);
	result = temp;
	while (*s1)
		*(temp++) = *(s1++);
	*(temp++) = '=';
	while (*s2)
		*(temp++) = *(s2++);
	*temp = '\0';
	return (result);
}

void make_node_to_envp(t_minishell *minishell)
{
	char	**envp;
	t_list	*lst_curr;
	int		idx;

	envp = (char **)malloc(sizeof(char *) * ft_lstsize(minishell->env_list));
	lst_curr = minishell->env_list;
	idx = 0;
	while (lst_curr)
	{
		envp[idx] = ft_env_strjoin(((t_env *)(lst_curr->content))->key,
			((t_env *)(lst_curr->content))->value);
		idx += 1;
		lst_curr = lst_curr->next;
	}
	minishell->ps_list.envp = envp;
}

int main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	env_linked_list(minishell, env);
	make_node_to_envp(minishell);
	while(minishell->ps_list)
	{
		printf("%s", *(minishell.ps_list->envp));
		minishell.ps_list = minishell.ps_list->next; 
	}
	return (0);
}