/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_len_utils.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:30:39 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:11 by seongyle         ###   ########seoul.kr  */
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
