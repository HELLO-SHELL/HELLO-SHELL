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

int	count_split_size(char *str)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (ft_strchr(" ", str[i]))
			i++;
		else
		{
			if (ft_strchr("<>", str[i]))
			{
				if (ft_strchr("<>", str[i + 1]))
					i++;
				i++;
			}
			else if (ft_strchr("\'\"", str[i]))
				skip_qoute_in_split(str, &i);
			else
			{
				while (str[i] != 0 && !(ft_strchr(" <>\'\"", str[i])))
					i++;
			}
			length++;
		}
	}
	// 나중에 아래 줄 삭제하기
	printf("split length: %d\n", length);
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
