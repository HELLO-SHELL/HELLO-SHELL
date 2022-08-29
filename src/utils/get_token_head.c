/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_token_head.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:16:06 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:16:07 by jaekim           ###   ########.fr       */
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
