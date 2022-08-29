/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_append_utils.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:27:47 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:29:04 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

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

char	*append_single_quote(
		char *input_buffer, char *input_ptr, int single_quote_len)
{
	char	*new_input_buffer;

	if (single_quote_len <= 0)
		return (input_buffer);
	new_input_buffer = safe_malloc(ft_strlen(input_buffer)
			+ single_quote_len + 1);
	ft_strlcpy(new_input_buffer, input_buffer, ft_strlen(input_buffer) + 1);
	ft_strlcpy(new_input_buffer
		+ ft_strlen(input_buffer), input_ptr, single_quote_len + 1);
	free(input_buffer);
	input_buffer = NULL;
	return (new_input_buffer);
}

char	*append_buffer_single_dollar(char *save)
{
	char	*buffer;
	char	*new;

	if (!save)
		return (NULL);
	buffer = "$";
	new = safe_malloc(ft_strlen(save) + ft_strlen(buffer) + 1);
	ft_strlcpy(new, save, ft_strlen(save) + 1);
	ft_strlcpy(new + ft_strlen(save), buffer, ft_strlen(buffer) + 1);
	free(save);
	save = NULL;
	return (new);
}

char	*append_buffer_after_all(char *save, char const *buffer)
{
	char	*new;

	if (buffer == NULL || !*buffer)
		return (save);
	else if (save == NULL && buffer)
	{
		new = malloc(ft_gnl_strlen(buffer) + 1);
		if (!new)
			return (NULL);
		ft_gnl_strlcpy(new, buffer, ft_gnl_strlen(buffer) + 1);
		return (new);
	}
	new = malloc(ft_gnl_strlen(save) + ft_gnl_strlen(buffer) + 1);
	if (!new)
		return (NULL);
	ft_gnl_strlcpy(new, save, ft_gnl_strlen(save) + 1);
	ft_gnl_strlcpy(new
		+ ft_gnl_strlen(save), buffer, ft_gnl_strlen(buffer) + 1);
	free(save);
	save = NULL;
	return (new);
}
