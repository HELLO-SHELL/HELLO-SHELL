#include "../../include/minishell.h"

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
			ft_error_exit("error");
	}
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
			ft_error_exit("error");
	}
}

int	handle_quote(t_split *split, char *line)
{
	split->flag = 0;
	while (line[split->i] != '\0')
	{
		if ((split->flag == 0 && line[split->i] == ' ')
			|| line[split->i] == '\0')
			break ;
		else if (line[split->i] == '\'')
			handle_single_quote(split, line);
		else if (line[split->i] == '\"')
			handle_double_quote(split, line);
		else
		{
			split->i++;
			split->rtn++;
		}
	}
	return (0);
}

int	check_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	count_split_size(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (check_white_space(str[i]))
			i++;
		else
		{
			while (str[i] != 0
				&& !(check_white_space(str[i])))
				i++;
			length++;
		}
	}
	return (length);
}

void	fill_char(t_split *split, char *line, int *i)
{
	split->str[*i] = line[split->j];
	(*i)++;
	(split->j)++;
}

int	fill_str(t_split *split, char *line)
{
	int	i;

	i = 0;
	split->str = safe_malloc(sizeof(char) * (split->rtn + 1));
	while (check_white_space(line[split->j]))
		(split->j)++;
	while (i < (split->rtn))
	{
		if (line[split->j] == '\'')
		{
			(split->j)++;
			while (line[split->j] != '\0' && line[split->j] != '\'')
				fill_char(split, line, &i);
		}
		else if (line[split->j] == '\"')
		{
			(split->j)++;
			while (line[split->j] != '\0' && line[split->j] != '\"')
				fill_char(split, line, &i);
		}
		else
			fill_char(split, line, &i);
	}
	(split->str)[i] = '\0';
	return (split->rtn);
}

int	split_line(t_split *split, char *line)
{
	split->rtn = 0;
	while (check_white_space(line[split->i]))
	{
		split->i++;
		if (line[split->i] == 0)
			return (0);
	}
	while (!check_white_space(line[split->i]) && line[split->i] != '\0')
	{
		if (line[split->i] == '\'' || line[split->i] == '\"')
		{
			if (handle_quote(split, line))
				return (0);
			break ;
		}
		split->rtn++;
		split->i++;
	}
	return (fill_str(split, line));
}
