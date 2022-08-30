/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_all_childs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:16:18 by jimin             #+#    #+#             */
/*   Updated: 2022/08/30 08:28:11 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	kill_all_childs(int input)
{
	t_process	*ps_curr;

	(void) input;
	ps_curr = g_minishell_info.ps_list;
	while (ps_curr)
	{
		kill(ps_curr->pid, SIGINT);
		ps_curr = ps_curr->next;
	}
}

void	kill_all_child(int input)
{
	t_process	*ps_curr;

	(void) input;
	ps_curr = g_minishell_info.ps_list;
	kill(ps_curr->pid, SIGINT);
}
