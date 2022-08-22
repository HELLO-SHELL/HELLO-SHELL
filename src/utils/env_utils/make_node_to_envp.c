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

void make_node_to_envp()
{
	char	**envp;
	t_list	*lst_curr;
	int		idx;

	envp = safe_malloc(sizeof(char *) * (ft_lstsize(g_minishell.env_list) + 1));
	lst_curr = g_minishell.env_list;
	idx = 0;
	while (lst_curr)
	{
		envp[idx] = ft_env_strjoin(((t_env *)(lst_curr->content))->key,
			((t_env *)(lst_curr->content))->value);
		if (is_same_string(((t_env *)(lst_curr->content))->key, "PATH"))
			(g_minishell.ps_list)->paths = ft_split(((t_env *)(lst_curr->content))->value, ':');
		idx++;
		lst_curr = lst_curr->next;
	}
	envp[idx] = NULL;
	g_minishell.ps_list->envp = envp;
	// 아래는 삭제해야겠지
	// idx = 0;
	// while (((g_minishell.ps_list)->paths)[idx])
	// {
	// 	ft_putstr_fd(((g_minishell.ps_list)->paths)[idx], 1);
	// 	ft_putstr_fd("\n", 1);
	// 	idx++;
	// }
}