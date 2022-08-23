#include "../../include/minishell.h"

int	_trans_status(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	else
		return (EXIT_FAILURE);
}

int	_signal_print(int status)
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

int	wait_child(pid_t pid)
{
	int	status;

	if (waitpid(pid, &status, 0) == -1)
		ft_error_exit("fail waitpid\n");
	if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGINT)
			print_error_message("\n");
		else if (WTERMSIG(status) == SIGQUIT)
			print_error_message("Quit: 3\n");
	}
	return (_trans_status(status));
}

pid_t	_get_last_pid()
{
	t_process *ps_curr;

	ps_curr = g_minishell_info.ps_list;
	while (ps_curr->next)
		ps_curr = ps_curr->next;
	return (ps_curr->pid);
}

int	wait_childs(void)
{
	const pid_t	last_pid = _get_last_pid();
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
			return (_trans_status(last_status));
		if (printed == 0)
			printed = _signal_print(status);
		if (pid == last_pid)
			last_status = status;
	}
}
