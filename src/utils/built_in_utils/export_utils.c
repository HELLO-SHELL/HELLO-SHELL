/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:00:49 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:03 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	update_value_when_overlap(t_env *temp, char *str)
{
	t_env	*updated_env;

	if (temp == NULL || str == NULL)
		return ;
	updated_env = temp;
	free(updated_env->value);
	updated_env->value = ft_substr(str + 1, 0, ft_strlen(str));
}

t_env	*get_overlap_env(char *key)
{
	t_env	*temp;

	temp = get_env_by_key(key);
	if (temp)
	{
		free(key);
		key = NULL;
		return (temp);
	}
	return (NULL);
}
