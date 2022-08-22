#include "../../../include/minishell.h"

int	get_env_len(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (check_white_space(*str) || *str == '\'' || *str == '\"' || *str == '$'
			|| *str == '|' || *str == '=' || *str == '/' || *str == '\\')
			break ;
		len++;
		str++;
	}
	return (len);
}

int	get_single_quote_len(char *input_ptr)
{
	if (ft_strchr(input_ptr, '\''))
		return (ft_strchr(input_ptr + 1, '\'') - ft_strchr(input_ptr, '\'') - 1);
	return (0);
}

int	get_under_single_quote_len(char *input_ptr)
{
	if (ft_strchr(input_ptr, '\''))
		return (ft_strchr(input_ptr, '\'') - input_ptr);
	return (0);
}

int get_under_dollar_len(char *input_ptr)
{
	if (ft_strchr(input_ptr, '?'))
		return (ft_strchr(input_ptr, '?') - input_ptr);
	return (0);	
}