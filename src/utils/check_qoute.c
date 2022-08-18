#include "../../include/minishell.h"

int	check_qoute(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}