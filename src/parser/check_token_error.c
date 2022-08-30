/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_token_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:10:10 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/30 08:04:32 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*check_near_token(t_token *token)
{
	char	*err_msg;

	err_msg = "";
	if (token->prev && is_special_token(token->prev->type))
	{
		if (!(token->prev->type == TK_PIPE
				&& token->type != TK_PIPE))
			err_msg = "special token can't stuck each other";
	}
	else if (token->next && is_special_token(token->next->type))
	{
		if (!(token->type == TK_PIPE
				&& token->next->type != TK_PIPE))
			err_msg = "special token can't stuck each other";
	}
	else if (token->prev == NULL && token->next == NULL)
		err_msg = "special token can't exist alone";
	return (err_msg);
}

int	check_token_error(t_token *token)
{
	t_token	*token_curr;
	char	*err_msg;

	token_curr = token;
	while (token_curr)
	{
		if (token_curr->prev == NULL && is_same_string(token_curr->value, "|"))
			err_msg = "pipe can not be located in the first location.";
		else if (token_curr->next == NULL
			&& is_same_string(token_curr->value, "|"))
			err_msg = "pipe can not be located in the last location.";
		else if (is_special_token(token_curr->type))
			err_msg = check_near_token(token_curr);
		if (!is_same_string("", err_msg))
		{
			print_error_message(err_msg);
			free_token_list(token);
			return (TRUE);
		}
		token_curr = token_curr->next;
	}
	return (FALSE);
}
