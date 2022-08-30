/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:59:10 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/31 01:58:23 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	unsetting(t_list *env_list, t_token *token)
{
	t_list	*curr;
	t_list	*temp;
	t_list	*env_prev;

	curr = env_list;
	while (curr)
	{
		temp = curr;
		if (is_same_string(((t_env *)temp->content)->key, token->value))
		{
			if (token->value == ((t_env *)temp->content)->key)
				env_list = temp->next;
			else
				env_prev->next = temp->next;
			safe_free (((t_env *)temp->content)->key);
			safe_free (((t_env *)temp->content)->value);
			safe_free((temp->content));
			safe_free(temp);
		}
		else
			env_prev = temp;
		curr = curr->next;
	}
}

int	ft_unset(void)
{
	t_list	*env_list;
	t_token	*token;

	env_list = g_minishell_info.env_list;
	token = g_minishell_info.ps_list->cmd_line;
	token = token->next;
	while (token)
	{
		unsetting(env_list, token);
		token = token->next;
	}
	return (EXIT_SUCCESS);
}
