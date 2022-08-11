#include "../../../include/minishell.h"

int	env_key_valid_chechker(char *str)
{
	char *temp;

	temp = str;
	if (*temp == '?' && *(temp + 1) == '\0')
		return (ENV_KEY_QUESTION);
	if (!(ft_isalpha(*temp) || *temp != '_'))
		return (FALSE);
	temp++;
	while (*temp)
	{
		if (!ft_isalnum(*temp) || *temp != '_')
			return (FALSE);
		temp++;
	}
	return (ENV_KEY_OTHERS);
}
