/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_by_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:04:04 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:06 by seongyle         ###   ########seoul.kr  */
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
