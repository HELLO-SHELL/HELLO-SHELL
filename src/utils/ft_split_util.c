#include "../../include/minishell.h"

int	handle_quote(char *line, int *count, int *idx)
{
	int	quotes;

	while (line[*idx] != '\0')
	{
		// "abc"de
		if (line[*idx] == '\'' || line[*idx] == '\"')
		{
			quotes = line[*idx];
			(*idx)++;
		}
		while ((quotes != line[*idx]) && ft_isalnum(line[*idx])) // 따옴표 확인
		{
			(*idx)++;
			(*count)++;
		}
		// 큰따옴표에서 작은따옴표로 바뀔 때 quote는 큰따옴표로 기억하기 때문에 에러가남
		// 음... 바로 위의 while문에 quote를 확인하고 변경하는 게 어떨까?
		// 공백 처리까지 해야함
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
	// line, 0부터 쿼트 뺴고 넣기
	int	z;
	int	j;

	z = 0;
	j = 0;
	while (z < rtn)
	{
		if (line[j] == '\'' || line[j] == '\"')
			j++;
		else
		{
			(*str)[z] = line[j];
			z++;
			j++;
		}
	}
	(*str)[z] = '\0';
	return (rtn);
}
