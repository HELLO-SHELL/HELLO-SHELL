#include "../../../include/minishell.h"

static int	get_env_len(char *str)
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

static char	*replace_dollar(char *input_buffer, char *temp, t_node *minishell)
{
	char	*replaced_value;
	char	*new_input_buffer;
	char	*temp_key;

	if (*temp == '?')
	{
		temp++;
		replaced_value = get_env_by_key(minishell->env_list, "?")->value;
		if (replaced_value)
			new_input_buffer = append_buffer(input_buffer, replaced_value);
	}
	else
	{
		temp_key = safe_malloc(get_env_len(temp));
		ft_memcpy(temp_key, temp, get_env_len(temp));
		temp += get_env_len(temp);
		replaced_value = get_env_by_key(minishell->env_list, temp_key)->value;
		free(temp_key);
		temp_key = NULL;
		if (replaced_value)
			new_input_buffer = append_buffer(input_buffer, replaced_value);
	}
	return (new_input_buffer);
}

char	*replace_whole_input_dollar(char *input, t_node *minishell)
{
	char	*input_buffer;
	char	*input_ptr;

	if (!ft_strchr(input, '$'))
		return (input);
	input_buffer = safe_malloc(ft_strlen(input));
	ft_memccpy(input_buffer, input, '$', ft_strlen(input));
	input_ptr = input;
	while (TRUE)
	{
		input_ptr = ft_strchr(input_ptr, '$');
		if (input_ptr)
			input_ptr += 1;
		if (env_key_valid_checker(input_ptr))
			input_buffer = replace_dollar(input_buffer, input_ptr, minishell);
		if (!input_ptr)
			break ;
	}
	free (input);
	input = NULL;
	return (input_buffer);
}