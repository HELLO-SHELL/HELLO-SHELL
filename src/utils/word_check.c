#include "../../include/minishell.h"

int	check_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	check_qoute(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

int	check_redirect_heredoc(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}