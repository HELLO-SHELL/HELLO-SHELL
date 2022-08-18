#include "../../../include/minishell.h"

int	check_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	count_split_size(char *str)
{
	// 파이프 및 리다이렉트(|,<,>,<<,>>, ', ") 단위를 추가해야하기 때문에 추가
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
			while (str[i] != 0 && !(check_white_space(str[i])))
				i++;
			length++;
		}
	}
	return (length);
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
		(split->j)++;
		while (line[split->j] != '\0' && line[split->j] != quote)
		{
			split->str[*i] = line[split->j];
			(*i)++;
			(split->j)++;
		}
		(split->j)++;
	}
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
