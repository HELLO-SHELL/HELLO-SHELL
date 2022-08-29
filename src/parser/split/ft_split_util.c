/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:09:52 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:09:53 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	handle_pipe_and_arrow(char *str, int *i, int *res)
{
	if (ft_strchr("<>|", str[*i]) && str[*i] != '\0')
		(*res)++;
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
		{
			(*res)++;
			(*i)++;
		}
		(*i)++;
	}
	else if (str[*i] == '>')
	{
		if (str[*i + 1] == '>')
		{
			(*res)++;
			(*i)++;
		}
		(*i)++;
	}
	else if (ft_strchr("|", str[*i]))
		(*i)++;
}

void	fill_char(t_split *split, char *line, int *i, char quote)
{
	if (quote == '\0')
	{
		split->str[*i] = line[split->j];
		(*i)++;
		split->j++;
	}	
	else
	{
		split->j++;
		while (line[split->j] != '\0' && line[split->j] != quote)
		{
			split->str[*i] = line[split->j];
			(*i)++;
			split->j++;
		}
		split->j++;
	}
}

int	fill_str(t_split *split, char *line)
{
	int	i;

	i = 0;
	split->str = safe_malloc(sizeof(char) * (split->rtn + 1));
	while (is_white_space(line[split->j]))
		(split->j)++;
	while (i < (split->rtn))
	{
		if (line[split->j] == '\'')
			fill_char(split, line, &i, '\'');
		else if (line[split->j] == '\"')
			fill_char(split, line, &i, '\"');
		else
			fill_char(split, line, &i, '\0');
	}
	split->str[i] = '\0';
	return (split->rtn);
}

int	split_line(t_split *split, char *line)
{
	split->rtn = 0;
	while (is_white_space(line[split->i]))
	{
		split->i++;
		if (line[split->i] == 0)
			return (0);
	}
	if (ft_strchr("<>|", line[split->i]) || is_white_space(line[split->i]))
		handle_pipe_and_arrow(line, &(split->i), &(split->rtn));
	else
	{
		while (!is_white_space(line[split->i])
			&& !ft_strchr("<>|\0", line[split->i]))
		{
			if (ft_strchr("\'\"", line[split->i]))
				handle_quote(split, line);
			else
			{
				split->rtn++;
				split->i++;
			}
		}
	}
	return (fill_str(split, line));
}
