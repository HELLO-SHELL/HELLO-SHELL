/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_len_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:30:39 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:30:40 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	get_env_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (is_dollar_replacement_end_condition(*str))
			break ;
		len++;
		str++;
	}
	return (len);
}

int	get_single_quote_len(char *input_ptr)
{
	if (ft_strchr(input_ptr, '\''))
		return (ft_strchr(input_ptr + 1, '\'')
			- ft_strchr(input_ptr, '\'') + 1);
	return (0);
}

int	get_under_single_quote_len(char *input_ptr)
{
	if (ft_strchr(input_ptr, '\''))
		return (ft_strchr(input_ptr, '\'') - input_ptr);
	return (0);
}

int	get_under_dollar_len(char *input_ptr)
{
	if (ft_strchr(input_ptr, '$'))
		return (ft_strchr(input_ptr, '$') - input_ptr);
	return (0);
}
