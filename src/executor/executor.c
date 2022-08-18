#include "../../include/minishell.h"

int	is_built_in(t_process *ps_info)
{
	char *cmd;

	cmd = ps_info->cmd_line->value[0];
	if (cmd == CD
		|| cmd == ENV
		|| cmd == PWD
		|| cmd == EXIT
		|| cmd == ECHO
		|| cmd == UNSET
		|| cmd == EXPORT
		)
		return (1);
	return (0);
};

void	execute_built_in(t_process *process)
{
	char *cmd;

	cmd = process->cmd_line->value[0];
	if (cmd == CD)
		ft_cd(void);
	else if (cmd == ENV)
		ft_env(void);
	else if (cmd == PWD)
		ft_pwd(void);
	else if (cmd == EXIT)
		ft_exit(void);
	else if (cmd == ECHO)
		ft_echo(void);
	else if (cmd == UNSET)
		ft_unset(void);
	else if (cmd == EXPORT)
		ft_export(void);	
	return ;
};

int	execute_command(t_process *process)
{
	char	*command;

	if (is_accessable_command(process->cmd_line, process->paths))
		command = get_accessable_command(process->cmd_line, process->paths);
	else
		ft_error_exit("command not found");
	return (execve(command, process->argv, process->envp));
}

void	execute_process(t_process *ps_info, t_pipes *pipes)
{
	apply_redirections(ps_info->cmd_line);
	safe_dup2(pipes->prev_pipe[READ], STDIN_FILENO);
	safe_dup2(pipes->next_pipe[WRITE], STDOUT_FILENO);
	safe_close_pipes(pipes);
	// 여기
	if (is_built_in(ps_info))
		execute_built_in(ps_info);
	else
		execute_command(ps_info);
}

void	execute_pipeline(t_minishell *minishell)
{
	int			idx;
	t_process	*ps_curr;

	idx = 0;
	ps_curr = minishell->ps_list;
	init_pipe(&minishell->pipes);
	while (ps_curr)
	{
		swap_pipe(&minishell->pipes);
		if (pipe(minishell->pipes.next_pipe))
			ft_error_exit("fail_pipe()");
		ps_curr->pid = fork();
		if (ps_curr->pid == -1)
			ft_error_exit("fail fork()\n");
		else if (ps_curr->pid == 0)
			execute_process(ps_curr, &(minishell->pipes));
		else
		{
			safe_close_pipe(&minishell->pipes.prev_pipe[READ]);
			safe_close_pipe(&minishell->pipes.next_pipe[WRITE]);
		}
		ps_curr = ps_curr->next;
	}
	wait_childs(minishell->ps_list);
}

void	execute_single_cmdline(t_process *process)
{
	pid_t	pid;
	apply_redirections(process->cmd_line);
	// 여기
	if (is_built_in(process))
		execute_built_in(process);
	else
	{
		pid = fork();
		if (pid == 0)
			execute_command(process);
		else
			wait_child(pid);
	}
}

void	executor(t_minishell *minishell)
{
	t_process	*ps_list;

	ps_list = minishell->ps_list;
	heredoc_to_temp_files(ps_list);
	if (ps_list->size == 1)
		execute_single_cmdline(ps_list);
	else
		execute_pipeline(minishell);
}
