#include "../../include/minishell.h"

int	env_key_valid_chechker(char *str)
{
	char *temp;

	temp = str;
	if (!(ft_isalpha(*temp) || *temp != '_'))
		return (0);
	temp++;
	while (*temp)
	{
		if (!ft_isalnum(*temp))
			return (0);
		temp++;
	}
	return (1);
}