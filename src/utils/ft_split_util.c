#include "../../include/minishell.h"

int	handle_quote(char *line, int *count, int *idx)
{
	int	quotes;

	while (line[*idx] != '\0')
	{
		// "abc"de
		if (line[*idx] == 34 || line[*idx] == 39)
		{
			quotes = line[*idx];
			(*idx)++;
		}
		while ((line[*idx] != 34 || line[*idx] != 39) && ft_isalnum(line[*idx])) // 따옴표 확인
		{
			(*idx)++;
			(*count)++;
		}
		if ((quotes != line[*idx]) && (line[*idx] != '\0'))
			return (1); //ft_error 로 바꿔야함.
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
			while (str[i] != 0
				&& !(check_white_space(str[i])))
				i++;
			length++;
		}
	}
	return (length);
}

int	split_line(char *line, char **str, int *i)
{
	int	rtn;

	rtn = 0;
	while (check_white_space(line[*i]))
	{
		(*i)++;
		if (line[*i] == 0)
			return (0);
	}
	while (!check_white_space(line[*i]) && line[*i] != '\0')
	{
		if (line[*i] == 34 || line[*i] == 39)
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
	ft_strlcpy((*str), line + (*i) - rtn, rtn + 1);
	return (rtn);
}
