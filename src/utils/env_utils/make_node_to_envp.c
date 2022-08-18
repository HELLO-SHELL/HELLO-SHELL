#include "../../../include/minishell.h"

static char	*ft_env_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*temp;

	temp = safe_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
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

	envp = safe_malloc(sizeof(char *) * ft_lstsize(minishell->env_list));
	lst_curr = minishell->env_list;
	idx = 0;
	while (lst_curr)
	{
		envp[idx] = ft_env_strjoin(((t_env *)(lst_curr->content))->key,
			((t_env *)(lst_curr->content))->value);
		idx++;
		lst_curr = lst_curr->next;
	}
	minishell->ps_list.envp = envp;
}