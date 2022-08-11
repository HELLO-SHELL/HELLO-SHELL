#include "../../../include/minishell.h"

int	handle_quote(char *line, int *count, int *idx)
{
	int	quotes;
	int	i;
	int	single_quotes;
	int	double_quotes;

	// 홀수 체크 check_odd_quotes(line)
	i = 0;
	single_quotes = 0;
	double_quotes = 0;
	while (line[i])
	{
		if (line[i] == '\'')
			single_quotes++;
		else if (line[i] == '\"')
			double_quotes++;
		i++;
	}
	if ((single_quotes % 2) || (double_quotes % 2))
		return (0);
	while (line[*idx] != '\0')
	{
		// "abc"de
		if (line[*idx] == '\'' || line[*idx] == '\"')
		{
			quotes = line[*idx];
			(*idx)++;
		}
		while ((line[*idx] != '\'' || line[*idx] != '\"')
				&& (ft_isalnum(line[*idx]) || (line[*idx] >= 9 && line[*idx] <= 13)
				|| line[*idx] == 32) ) // 따옴표 확인
		{
			(*idx)++;
			(*count)++;
			if ((line[*idx] == '\'' || line[*idx] == '\"'))
				quotes = line[*idx];
		}
		if ((quotes != line[*idx]) && (line[*idx] != '\0'))
			return (1);
		else if (line[*idx] == '\0')
			return (0);
		(*idx)++;
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
			while (str[i] != 0 && !(check_white_space(str[i])))
				i++;
			length++;
		}
	}
	return (length);
}

int	split_line(char *line, char **str, int *i)
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
			if (handle_quote(line, &rtn, i))
				return (0);
			break ;
		}
		rtn++;
		(*i)++;
	}
	(*str) = malloc(sizeof(char) * rtn + 1);
	if (!(*str))
		exit(EXIT_FAILURE);
	// line, 0부터 쿼트 뺴고 넣기
	int	z;
	int	j;

	z = 0;
	//export a=b 일때 t와 a 사이의 공백을 넘기는 식
	if ((line[*j] >= 9 && line[*j] <= 13) || line[*j] == 32)
		(*j)++;
	while (z < rtn)
	{
		if (line[j] == '\'' || line[j] == '\"')
			j++;
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
			(*str)[z] = line[j];
			z++;
			j++;
		}
		split->rtn++;
		split->i++;
	}
	return (fill_str(split, line));
}
