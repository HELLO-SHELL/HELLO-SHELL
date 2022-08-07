#include "../../include/minishell.h"

int	handle_quote(char *line, int *count, int *idx)
{
	int flag;

	flag = 0;
	while (line[*idx] != '\0') //echo 'abc'"de" abc'def'
	{
		if ((flag == 0 && line[*idx] == ' ') || line[*idx] == '\0')//
			break ;
		else if (line[*idx] == '\'')
		{
			flag = 1;
			(*idx)++;
			while (line[*idx] != '\0' && flag == 1)
			{
				if (line[*idx] != '\'')
				{
					(*idx)++;
					(*count)++;
				}
				else if (line[*idx] == '\'')
				{
					flag = 0;
					(*idx)++;
				}
				else
					ft_error_exit("error");
			}
		}
		else if (line[*idx] == '\"')
		{
			flag = 1;
			(*idx)++;
			while (line[*idx] != '\0' && flag == 1)
			{
				if (line[*idx] != '\"')
				{
					(*idx)++;
					(*count)++;
				}
				else if (line[*idx] == '\"')
				{
					flag = 0;
					(*idx)++;
				}
				else
					ft_error_exit("error");
			}
		}
		else
		{
			(*idx)++;
			(*count)++;
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

int	split_line(char *line, char **str, int *i, int *j)
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
		if (line[*i] == '\'' || line[*i] == '\"')
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
	int	z;

	z = 0;
	while (check_white_space(line[*j]) || (line[*j] == '\'' || line[*j] == '\"'))
		(*j)++;
	while (z < rtn)
	{
		if (line[*j] == '\'' || line[*j] == '\"')
			(*j)++;
		else
		{
			(*str)[z] = line[*j];
			z++;
			(*j)++;
		}
	}
	(*str)[z] = '\0';
	return (rtn);
}
