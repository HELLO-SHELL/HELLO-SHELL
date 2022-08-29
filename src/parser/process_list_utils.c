/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_list_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:10:15 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:10:17 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	tk_listdelone(t_token **tk_list)
{
	if ((*tk_list)->prev)
		(*tk_list)->prev->next = (*tk_list)->next;
	if ((*tk_list)->next)
		(*tk_list)->next->prev = (*tk_list)->prev;
	(*tk_list)->prev = NULL;
	(*tk_list)->next = NULL;
	free((*tk_list)->value);
	(*tk_list)->value = NULL;
	free(*tk_list);
	(*tk_list) = NULL;
}

void	pslist_new(t_process **lst)
{
	t_process	*ps_temp;

	ps_temp = safe_malloc(sizeof(t_process));
	ps_temp->argv = NULL;
	ps_temp->cmd_line = NULL;
	ps_temp->next = NULL;
	(*lst) = ps_temp;
}

void	pslist_addback(t_process **lst)
{
	t_process	*lst_idx;
	t_process	*ps_temp;

	lst_idx = *lst;
	ps_temp = safe_malloc(sizeof(t_process));
	while (lst_idx->next)
	{
		lst_idx = lst_idx->next;
	}
	ps_temp->argv = NULL;
	ps_temp->cmd_line = NULL;
	ps_temp->next = NULL;
	lst_idx->next = ps_temp;
}

void	init_pslist(t_process **lst, int cnt)
{
	int	i;

	i = 0;
	while (i <= cnt)
	{
		if (i == 0)
			pslist_new(lst);
		else
			pslist_addback(lst);
		i++;
	}
}
