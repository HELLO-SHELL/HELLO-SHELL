/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_node_to_envp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:04:14 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/31 02:48:21 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static char	*ft_env_strjoin(char *s1, char *s2)
{
	char	*result;
	char	*temp;

	if (!s1)
		return (0);
	temp = safe_malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!temp)
		return (0);
	result = temp;
	while (*s1)
		*(temp++) = *(s1++);
	if (!s2)
		return (result);
	*(temp++) = '=';
	while (!*s2)
		*(temp++) = *(s2++);
	*temp = '\0';
	return (result);
}

void	make_node_to_envp(void)
{
	char	**envp;
	t_list	*lst_curr;
	int		idx;

	envp = safe_malloc(sizeof(char *)
			* (ft_lstsize(g_minishell_info.env_list) + 1));
	lst_curr = g_minishell_info.env_list;
	idx = 0;
	while (lst_curr)
	{
		envp[idx] = ft_env_strjoin(((t_env *)(lst_curr->content))->key,
				((t_env *)(lst_curr->content))->value);
		if (is_same_string(((t_env *)(lst_curr->content))->key, "PATH"))
			(g_minishell_info.ps_list)->paths
				= ft_split(((t_env *)(lst_curr->content))->value, ':');
		idx++;
		lst_curr = lst_curr->next;
	}
	envp[idx] = NULL;
	g_minishell_info.ps_list->envp = envp;
}
