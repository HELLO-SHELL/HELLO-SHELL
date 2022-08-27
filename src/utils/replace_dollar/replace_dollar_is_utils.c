#include "../../../include/minishell.h"

int is_symbol_in_dollar_replace(char c)
{
	if (c == '-' || c == '_')
		return (TRUE);
	if (c == '#' || c == '@' || c == '*')
		return (TRUE);
	if (c == '!' || c == '$' || c == '?')
		return (TRUE);
	return (FALSE);
}

int	is_only_dollar(char *input_ptr)
{
	if (*input_ptr != '$')
		return (FALSE);
	input_ptr++;
	if (ft_isalnum(*input_ptr))
		return (FALSE);
	if (is_symbol_in_dollar_replace(*input_ptr))
		return (FALSE);
	return (TRUE);
}

int	is_dollar_replacement_end_condition(char c)
{
	if (is_white_space(c))
		return (TRUE);
	if (c == '\'' || c == '\"' || c == '\\')
		return (TRUE);
	if (c == '|' || c == '=' || c == '/')
		return (TRUE);
	if (c == '$' || c == '-')
		return (TRUE);
	return (FALSE);
}
