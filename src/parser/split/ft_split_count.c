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

static void	skip_word(char *str, int *i, int *res)
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
	// ft_putstr_fd("splitted size : ", 1);
	// ft_putnbr_fd(length, 1);
	// ft_putstr_fd("\n", 1);
	return (length);
}