/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_count.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:09:40 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:09:40 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static void	skip_qoute_in_split(char *str, int *i)
{
	char	qoute;

	qoute = str[*i];
	while (str[*i])
	{
		(*i)++;
		if (str[*i] == qoute)
			break ;
	}
	if (!str[*i])
		error_exit("qoute parse error");
	else
		(*i)++;
}

static void	skip_word(char *str, int *i, int *res)
{
	if (ft_strchr("<>|", str[*i]) && str[*i] != '\0')
		(*res)++;
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
			(*i)++;
		(*i)++;
	}
	else if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
			(*i)++;
		(*i)++;
	}
	else if (ft_strchr("|", str[*i]))
		(*i)++;
}

int	count_split_size(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		while (is_white_space(str[i]))
			i++;
		while (!ft_strchr("<>|\0", str[i]) && !is_white_space(str[i]))
		{
			if (ft_strchr("\'\"", str[i]))
				skip_qoute_in_split(str, &i);
			else
				i++;
			if (ft_strchr("<>|\0", str[i]) || is_white_space(str[i]))
				length++;
		}
		if (ft_strchr("<>|\0", str[i]) || is_white_space(str[i]))
			skip_word(str, &i, &length);
	}
	return (length);
}
