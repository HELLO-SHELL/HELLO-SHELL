/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:16:06 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:09 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_token	*get_token_head(t_token *token)
{
	while (token)
	{
		if (token->prev == NULL)
			return (token);
		token = token->prev;
	}
	return (NULL);
}
