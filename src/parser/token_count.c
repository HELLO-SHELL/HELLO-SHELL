/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:10:26 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:10:27 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	token_word_count(t_token *token)
{
	t_token	*token_curr;
	int		count;

	count = 0;
	token_curr = token;
	while (token_curr)
	{
		if (token_curr->type == TK_WORD)
			count++;
		token_curr = token_curr->next;
	}
	return (count);
}
