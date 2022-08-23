#include "../../../include/minishell.h"

static char	*replace_dollar(char *input_buffer, char *temp)
{
	char	*replaced_value;
	char	*new_input_buffer;
	char	*temp_key;

	if (*temp == '?')
		replaced_value = g_minishell_info.last_status;
	else
	{
		temp_key = safe_malloc(get_env_len(temp));
		ft_strlcpy(temp_key, temp, get_env_len(temp) + 1);
		replaced_value = get_env_value_by_key(temp_key);
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
	int	s_quote_len;

	if (!**input_ptr || !*input_ptr)
		return ;
	if (ft_strchr(*input_ptr, '\'') < ft_strchr(*input_ptr, '$'))
	{
		*input_buffer = \
			append_buffer_under_single_quote(*input_buffer, *input_ptr);
		*input_ptr += get_under_single_quote_len(*input_ptr);
		s_quote_len = get_single_quote_len(*input_ptr);
		*input_buffer = \
			append_single_quote(*input_buffer, *input_ptr, s_quote_len);
		if (s_quote_len > 0)
			*input_ptr += (s_quote_len + 2);
	}
}

static void	make_dollar_replaced_input(\
	char **input_buffer, char **input_ptr)
{
	while (TRUE)
	{
		if (!ft_strchr(*input_ptr, '$'))
		{
			*input_buffer = append_buffer_after_all(*input_buffer, *input_ptr);
			break ;
		}
		*input_ptr = ft_strchr(*input_ptr, '$');
		if (*input_ptr)
			*input_ptr += 1;
		if (env_key_valid_checker(*input_ptr))
		{
			*input_buffer = \
				replace_dollar(*input_buffer, *input_ptr);
			*input_ptr += get_env_len(*input_ptr);
		}
		handle_single_quote(&*input_buffer, &*input_ptr);
		*input_buffer = append_buffer_under_dollar(*input_buffer, *input_ptr);
		*input_ptr += get_under_dollar_len(*input_ptr);
	}
}

int	is_not_single_quote_validate(char *input)
{
	int	cnt_single_quote;

	cnt_single_quote = 0;
	while (*input)
	{
		if (*input == '\'')
			cnt_single_quote += 1;
		input++;
	}
	return (cnt_single_quote % 2);
}

char	*replace_whole_input_dollar(char *input)
{
	char	*input_buffer;
	char	*input_ptr;

	if (is_not_single_quote_validate(input))
	{
		print_error_message("no valid single quote count, please input again");
		free(input);
		return (NULL);
	}
	if (!ft_strchr(input, '$'))
		return (input);
	input_buffer = safe_malloc(ft_strlen(input));
	input_ptr = input;
	handle_single_quote(&input_buffer, &input_ptr);
	input_buffer = append_buffer_under_dollar(input_buffer, input_ptr);
	make_dollar_replaced_input(&input_buffer, &input_ptr);
	free(input);
	input = NULL;
	return (input_buffer);
}
