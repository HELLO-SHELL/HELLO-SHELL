/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_key_valid_checker.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:03:57 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/01 16:55:36 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	env_key_valid_checker(char *str)
{
	char	*temp;

	if (!str)
		return (FALSE);
	temp = str;
	if (*temp != '$')
		return (FALSE);
	temp++;
	if (!(ft_isalpha(*temp) || *temp == '_'))
		return (FALSE);
	temp++;
	while (*temp)
	{
		if (is_dollar_replacement_end_condition(*temp))
			break ;
		if (!(ft_isalnum(*temp) || *temp == '_'))
			return (FALSE);
		temp++;
	}
	return (ENV_KEY_OTHERS);
}
