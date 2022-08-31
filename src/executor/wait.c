/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:16:29 by jimin             #+#    #+#             */
/*   Updated: 2022/08/31 11:50:42 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	trans_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	else
		return (EXIT_FAILURE);
}

int	signal_print(int status)
{
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			print_error_message("\n");
		else if (WTERMSIG(status) == SIGQUIT)
			print_error_message("Quit: 3\n");
		else
			return (0);
		return (1);
	}
	return (0);
}

pid_t	get_last_pid(void)
{
	t_process	*ps_curr;

	ps_curr = g_minishell_info.ps_list;
	while (ps_curr->next)
		ps_curr = ps_curr->next;
	return (ps_curr->pid);
}

int	wait_child(int pid)
{
	int			status;

	waitpid(pid, &status, 0);
	return (trans_status(status));
}

int	wait_childs(void)
{
	const pid_t	last_pid = get_last_pid();
	pid_t		pid;
	int			status;
	int			last_status;
	int			printed;

	printed = 0;
	last_status = 1;
	while (42)
	{
		pid = wait(&status);
		if (pid == -1)
			return (trans_status(last_status));
		if (printed == 0)
			printed = signal_print(status);
		if (pid == last_pid)
			last_status = status;
	}
}
