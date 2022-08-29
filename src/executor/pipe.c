/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:16:21 by jimin             #+#    #+#             */
/*   Updated: 2022/08/29 18:16:22 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_pipe(t_pipes *p)
{
	swap(&(p->prev_pipe[READ]), &(p->next_pipe[READ]));
	swap(&(p->prev_pipe[WRITE]), &(p->next_pipe[WRITE]));
}

void	init_pipe(t_pipes *p)
{
	p->prev_pipe[READ] = -1;
	p->prev_pipe[WRITE] = -1;
	p->next_pipe[READ] = -1;
	p->next_pipe[WRITE] = -1;
}
