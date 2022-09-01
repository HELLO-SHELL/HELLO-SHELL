/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_validator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:15:04 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:04 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	quote_validator(char *input)
{
	int		i;
	char	*str;
	char	quote;

	i = 0;
	str = input;
	while (*str && str)
	{
		if (*str == '\'' || *str == '\"')
		{
			quote = *str;
			str++;
			str = ft_strchr(str, quote);
			if (str == NULL)
			{
				print_error_message("qoute parse error");
				return (FAILURE);
			}
		}
		str++;
	}
	return (SUCCESS);
}
