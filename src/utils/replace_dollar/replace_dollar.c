/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:24:48 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:24:49 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

char	*replace_dollar_in_heredoc(char *input)
{
	char	*input_buffer;
	char	*input_ptr;

	if (!ft_strchr(input, '$'))
		return (input);
	input_buffer = safe_malloc(ft_strlen(input));
	input_ptr = input;
	input_buffer = append_buffer_under_dollar(input_buffer, input_ptr);
	make_dollar_replaced_input(&input_buffer, &input_ptr);
	free(input);
	input = NULL;
	return (input_buffer);
}

char	*replace_whole_input_dollar(char *input)
{
	char	*input_buffer;
	char	*input_ptr;

	if (!ft_strchr(input, '$'))
		return (input);
	input_buffer = safe_malloc(ft_strlen(input));
	input_ptr = input;
	r_handle_single_quote(&input_buffer, &input_ptr);
	input_buffer = append_buffer_under_dollar(input_buffer, input_ptr);
	make_dollar_replaced_input(&input_buffer, &input_ptr);
	free(input);
	input = NULL;
	return (input_buffer);
}
