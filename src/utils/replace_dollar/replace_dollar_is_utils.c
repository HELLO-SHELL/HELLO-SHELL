/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_is_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:20:03 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:10 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_symbol_in_dollar_replace(char *input_ptr)
{
	if (*input_ptr != '$')
		return (FALSE);
	input_ptr++;
	if (*input_ptr == '-' || *input_ptr == '_')
		return (TRUE);
	if (*input_ptr == '#' || *input_ptr == '@' || *input_ptr == '*')
		return (TRUE);
	if (*input_ptr == '!' || *input_ptr == '$' || *input_ptr == '?')
		return (TRUE);
	return (FALSE);
}

int	is_only_dollar(char *input_ptr)
{
	if (*input_ptr != '$')
		return (FALSE);
	input_ptr++;
	if (ft_isalnum(*input_ptr))
		return (FALSE);
	if (is_symbol_in_dollar_replace(--input_ptr))
		return (FALSE);
	return (TRUE);
}

int	is_dollar_replacement_end_condition(char c)
{
	if (is_white_space(c))
		return (TRUE);
	if (c == '\'' || c == '\"' || c == '\\')
		return (TRUE);
	if (c == '|' || c == '=' || c == '/')
		return (TRUE);
	if (c == '$' || c == '-')
		return (TRUE);
	return (FALSE);
}
