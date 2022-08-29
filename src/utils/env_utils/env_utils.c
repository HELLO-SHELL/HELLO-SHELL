/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:07:10 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:07:14 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	split_env(t_env *env_node, char **env, int i)
{
	char	*key;
	char	*delimiter;
	char	*value;

	delimiter = ft_strchr(env[i], '=');
	*delimiter = '\0';
	key = env[i];
	value = delimiter + 1;
	env_node->key = ft_strdup(key);
	env_node->value = ft_strdup(value);
}

void	env_linked_list(char **env)
{
	t_env	*env_node;
	int		i;

	i = 0;
	while (env[i])
	{
		env_node = safe_malloc(sizeof(t_env));
		env_node->key = NULL;
		env_node->value = NULL;
		split_env(env_node, env, i);
		ft_lstadd_back(&g_minishell_info.env_list, ft_lstnew(env_node));
		i++;
	}
}
