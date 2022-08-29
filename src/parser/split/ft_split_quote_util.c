/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quote_util.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:09:47 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:09:48 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	handle_single_quote(t_split *split, char *line)
{
	split->flag = 1;
	split->i++;
	while (line[split->i] != '\0' && split->flag == 1)
	{
		if (line[split->i] != '\'')
		{
			split->i++;
			split->rtn++;
		}
		else if (line[split->i] == '\'')
		{
			split->flag = 0;
			split->i++;
		}
		else
			error_exit("error");
	}
	if (split->flag == 1)
		error_exit("error");
}

void	handle_double_quote(t_split *split, char *line)
{
	split->flag = 1;
	split->i++;
	while (line[split->i] != '\0' && split->flag == 1)
	{
		if (line[split->i] != '\"')
		{
			split->i++;
			split->rtn++;
		}
		else if (line[split->i] == '\"')
		{
			split->flag = 0;
			split->i++;
		}
		else
			error_exit("error");
	}
	if (split->flag == 1)
		error_exit("error");
}

int	handle_quote(t_split *split, char *line)
{
	split->flag = 0;
	if (line[split->i] == '\'')
		handle_single_quote(split, line);
	else if (line[split->i] == '\"')
		handle_double_quote(split, line);
	return (0);
}
