/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_by_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:04:04 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:04:05 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

t_env	*get_env_by_key(char *key)
{
	t_list	*temp;

	temp = g_minishell_info.env_list;
	while (temp)
	{
		if (is_same_string(((t_env *)temp->content)->key, key))
			return ((t_env *)temp->content);
		temp = temp->next;
	}
	return (NULL);
}

char	*get_env_value_by_key(char *key)
{
	t_list	*temp;

	temp = g_minishell_info.env_list;
	while (temp)
	{
		if (is_same_string(((t_env *)temp->content)->key, key))
			return (((t_env *)(temp->content))->value);
		temp = temp->next;
	}
	return (NULL);
}
