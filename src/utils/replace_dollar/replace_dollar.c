#include "../../../include/minishell.h"

static char	*replace_dollar(char *input_buffer, char *temp, t_minishell *minishell)
{
	char	*replaced_value;
	char	*new_input_buffer;
	char	*temp_key;

	if (*temp == '?')
	{
		temp++;
		// 실행부에서 ? 처리예정 (ex. last status ...)
		replaced_value = get_env_value_by_key(minishell->env_list, "?");
	}
	else
	{
		temp_key = safe_malloc(get_env_len(temp));
		ft_strlcpy(temp_key, temp, get_env_len(temp) + 1);
		replaced_value = get_env_value_by_key(minishell->env_list, temp_key);
		free(temp_key);
		temp_key = NULL;
	}
	if (replaced_value)
		new_input_buffer = append_buffer(input_buffer, replaced_value);
	else
		new_input_buffer = input_buffer;
	return (new_input_buffer);
}

static void	handle_single_quote(char **input_buffer, char **input_ptr)
{
	if (ft_strchr(*input_ptr, '\'') < ft_strchr(*input_ptr, '$'))
	{
		*input_buffer = append_buffer_under_single_quote(*input_buffer, *input_ptr);
		*input_ptr += get_under_single_quote_len(*input_ptr);
		*input_buffer = append_single_quote(*input_buffer, *input_ptr, get_single_quote_len(*input_ptr));
		if (get_single_quote_len(*input_ptr) > 0)
			*input_ptr += get_single_quote_len(*input_ptr) + 2;
	}
}

char	*replace_whole_input_dollar(char *input, t_minishell *minishell)
{
	char	*input_buffer;
	char	*input_ptr;
	
	if (!ft_strchr(input, '$'))
		return (input);
	input_buffer = safe_malloc(ft_strlen(input));
	input_ptr = input;
	handle_single_quote(&input_buffer, &input_ptr);
	ft_memccpy_under(input_buffer, input_ptr, '$', ft_strlen(input_ptr));
	while (TRUE)
	{
		input_ptr = ft_strchr(input_ptr, '$');
		if (input_ptr)
			input_ptr += 1;
		if (env_key_valid_checker(input_ptr))
		{
			input_buffer = replace_dollar(input_buffer, input_ptr, minishell);
			input_ptr += get_env_len(input_ptr);
		}
		if (!input_ptr)
			break ;
		handle_single_quote(&input_buffer, &input_ptr);
		if (ft_strchr(input_ptr, '$'))
		{
			input_buffer = append_buffer_under_dollar(input_buffer, input_ptr);
			input_ptr += (ft_strchr(input_ptr, '$') - input_ptr);
		}
		else
		{
			input_buffer = append_buffer(input_buffer, input_ptr);
			break ;
		}
	}
	free(input);
	input = NULL;
	return (input_buffer);
}