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

char	*append_buffer_under_dollar(char *save, char const *buffer)
{
	char	*new;
	char	*temp;
	char	origin_value;

	temp = ft_strchr(buffer, '$');
	if (buffer == NULL || temp == NULL)
		return (save);
	origin_value = *temp;
	*temp = '\0';
	if (save == NULL && buffer)
	{
		new = safe_malloc(ft_strlen(buffer) + 1);
		ft_strlcpy(new, buffer, ft_strlen(buffer) + 1);
		return (new);
	}
	new = safe_malloc(ft_strlen(save) + ft_strlen(buffer) + 1);
	ft_strlcpy(new, save, ft_strlen(save) + 1);
	ft_strlcpy(new + ft_strlen(save), buffer, ft_strlen(buffer) + 1);
	free(save);
	save = NULL;
	*temp = origin_value;
	return (new);
}
char	*append_buffer_under_single_quote(char *save, char const *buffer)
{
	char	*new;
	char	*temp;
	char	origin_value;

	temp = ft_strchr(buffer, '\'');
	if (buffer == NULL || temp == NULL)
		return (save);
	origin_value = *temp;
	*temp = '\0';
	if (save == NULL && buffer)
	{
		new = safe_malloc(ft_strlen(buffer) + 1);
		ft_strlcpy(new, buffer, ft_strlen(buffer) + 1);
		return (new);
	}
	new = safe_malloc(ft_strlen(save) + ft_strlen(buffer) + 1);
	ft_strlcpy(new, save, ft_strlen(save) + 1);
	ft_strlcpy(new + ft_strlen(save), buffer, ft_strlen(buffer) + 1);
	free(save);
	save = NULL;
	*temp = origin_value;
	return (new);
}

char	*append_single_quote(char *input_buffer, char *input_ptr, int single_quote_len)
{
	char	*new_input_buffer;

	if (single_quote_len <= 0)
		return ;
	new_input_buffer = safe_malloc(ft_strlen(input_buffer) + single_quote_len + 1);
	ft_strlcpy(new_input_buffer, input_buffer, ft_strlen(input_buffer) + 1);
	fr_strlcpy(new_input_buffer + ft_strlen(input_buffer), input_ptr, single_quote_len + 1);
	free(input_buffer);
	input_buffer = NULL;
	return (new_input_buffer);
}

static int	get_single_quote_len(char *input_ptr)
{
	int	i;

	i = ft_strchr(input_ptr + 1, '\'') - ft_strchr(input_ptr, '\'') - 1;
	return (i);
}

char	*replace_whole_input_dollar(char *input, t_minishell *minishell)
{
	char	*input_buffer;
	char	*input_ptr;
	int		single_quote_len;
	
	if (!ft_strchr(input, '$'))
		return (input);
	input_buffer = safe_malloc(ft_strlen(input));
	input_ptr = input;
	single_quote_len = get_single_quote_len(input_ptr);
	if (ft_strchr(input_ptr, '\'') < ft_strchr(input_ptr, '$'))
	{
		input_buffer = append_buffer_under_single_quote(input_buffer, input_ptr);
		input_ptr += (ft_strchr(input_ptr, '\'') - input_ptr);
		input_buffer = append_single_quote(input_buffer, input_ptr, get_single_quote_len(input_ptr));
	}
	ft_memccpy_under(input_buffer + single_quote_len, input_ptr, '$', ft_strlen(input_ptr));
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
		if (ft_strchr(input_ptr, '\'') < ft_strchr(input_ptr, '$'))
		{
			input_buffer = append_buffer_under_single_quote(input_buffer, input_ptr);
			input_ptr = (ft_strchr(input_ptr, '\'') - input_ptr);
			handle_single_quote(&input_buffer, &input_ptr, get_single_quote_len(input_ptr));
		}
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