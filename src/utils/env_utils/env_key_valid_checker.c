#include "../../../include/minishell.h"

static int	possible_next_question(char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (is_dollar_replacement_end_condition(*str))
			break ;
		len++;
		str++;
	}
	if (len == 0)
		return (TRUE);
	return (FALSE);
}

int	env_key_valid_checker(char *str)
{
	char	*temp;

	if (!str)
		return (FALSE);
	temp = str;
	if (*temp != '$')
		return (FALSE);
	temp++;
	if (*temp == '?' && possible_next_question(temp + 1))
		return (ENV_KEY_QUESTION);
	if (!(ft_isalpha(*temp) || *temp == '_'))
		return (FALSE);
	temp++;
	while (*temp)
	{
		if (is_dollar_replacement_end_condition(*temp))
			break ;
		if (!(ft_isalnum(*temp) || *temp == '_'))
			return (FALSE);
		temp++;
	}
	return (ENV_KEY_OTHERS);
}
