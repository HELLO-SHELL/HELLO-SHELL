#include "../../../include/minishell.h"

static void	skip_qoute_in_split(char *str, int *i)
{
	char	qoute;

	qoute = str[*i];
	while (str[*i])
	{
		(*i)++;
		if (str[*i] == qoute)
			break;
	}
	if (!str[*i])
		ft_error_exit("qoute parse error");
	else
		(*i)++;
}

void	skip_word(char *str, int *i, int *res)
{
	if (ft_strchr("<>|", str[*i]) && str[*i] != '\0')
	{
		(*res)++;
	}
	if (str[*i] == '<')
	{
		if (str[*i + 1] == '<')
			(*i)++;
		(*i)++;
	}
	if (str[*i] == '>')
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
	// 파이프 및 리다이렉트(|,<,>,<<,>>, ', ") 단위를 추가해야하기 때문에 추가
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
	// 나중에 아래 줄 삭제하기
	ft_putstr_fd("splitted size : ", 1);
	ft_putnbr_fd(length, 1);
	ft_putstr_fd("\n", 1);
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
	while (!is_white_space(line[split->i]) && !ft_strchr("|<>\0", line[split->i]))
	{
		if (ft_strchr("\'\"", line[split->i]))
		{
			handle_quote(split, line);
			if (is_white_space(line[split->i]))
				break ;
		}
		split->rtn++;
		split->i++;
	}
	if (ft_strchr("|<>", line[split->i]) && split->rtn == 0)
	{
		if (ft_strchr("<>", line[split->i]) && ft_strchr("<>", line[split->i + 1]))
		{
			split->rtn++;
			split->i++;
		}
		split->rtn++;
	}
	return (fill_str(split, line));
}
