#include "../../include/minishell.h"

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
				&& !check_white_space(str[i]))
				i++;
			length++;
		}
	}
	return (length);
}

int	check_size(char *line, char **str, int *i)
{
	int		rtn;

	rtn = 0;
	while (check_white_space(line[*i]))
	{
		(*i)++;
		if (line[*i] == 0)
			return (0);
	}
	while (!check_white_space(line[*i]) && line[*i] != '\0')
	{
		rtn++;
		(*i)++;
	}
	(*str) = malloc(sizeof(char) * rtn + 1);
	if (!(*str))
		exit(1);
	ft_strlcpy((*str), line + (*i) - rtn , rtn + 1);
	printf("ft_strlcpy %s\n", (*str));
	return (rtn);
}
