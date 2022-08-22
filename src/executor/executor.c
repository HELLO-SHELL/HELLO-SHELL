#include "../../include/minishell.h"

int	check_cmd(char *word)
{
	if (is_same_string(word, CD)
		|| is_same_string(word, ENV)
		|| is_same_string(word, PWD)
		|| is_same_string(word, EXIT)
		|| is_same_string(word, ECHO)
		|| is_same_string(word, UNSET)
		|| is_same_string(word, EXPORT)
		)
		return (1);
	return (0);
}

int	is_built_in(t_process *ps_info)
{
	char *word;

	word = ps_info->cmd_line->value;
	if (check_cmd(word))
		return (1);
	return (0);
}

void	execute_built_in(t_process *process)
{
	char *cmd;

	cmd = process->cmd_line->value;
	if (is_same_string(cmd, CD))
		ft_cd();
	else if (is_same_string(cmd, PWD))
		ft_pwd();
	else if (is_same_string(cmd, ENV))
		ft_env(g_minishell.env_list);
	else if (is_same_string(cmd, EXPORT))
		ft_export();
	else if (is_same_string(cmd, EXIT))
		ft_exit(0, "exit");
	else if (is_same_string(cmd, UNSET))
		ft_unset();
	// else if (cmd == ECHO)
	// 	ft_echo(void);
	return ;
}

int	execute_command(t_process *process)
{
	char	*command;

	if (is_accessable_command(process->cmd_line, process->paths))
		command = get_accessable_command(process->cmd_line, process->paths);
	else
		ft_error_exit("command not found");
	return (execve(command, process->argv, process->envp));
}

void	execute_process(t_process *process, t_pipes *pipes)
{
	apply_redirections(process->cmd_line);
	safe_dup2(pipes->prev_pipe[READ], STDIN_FILENO);
	safe_dup2(pipes->next_pipe[WRITE], STDOUT_FILENO);
	safe_close_pipes(pipes);
	// 여기
	if (is_built_in(process))
		execute_built_in(process);
	else
		execute_command(process);
}

void	execute_pipeline(void)
{
	int			idx;
	t_process	*ps_curr;

	idx = 0;
	ps_curr = g_minishell.ps_list;
	init_pipe(&g_minishell.pipes);
	while (ps_curr)
	{
		swap_pipe(&g_minishell.pipes);
		if (pipe(g_minishell.pipes.next_pipe))
			ft_error_exit("fail_pipe()");
		ps_curr->pid = fork();
		if (ps_curr->pid == -1)
			ft_error_exit("fail fork()\n");
		else if (ps_curr->pid == 0)
			execute_process(ps_curr, &(g_minishell.pipes));
		else
		{
			safe_close_pipe(&g_minishell.pipes.prev_pipe[READ]);
			safe_close_pipe(&g_minishell.pipes.next_pipe[WRITE]);
		}
		ps_curr = ps_curr->next;
	}
	g_minishell.last_status = wait_childs();
}

void	execute_single_cmdline(void)
{
	pid_t		pid;
	t_process	*process;

	process = g_minishell.ps_list;
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

void	executor(void)
{
	heredoc_to_temp_files();
	// size 설정이 잘 안됨 -> 원인 파악 필요
	if (g_minishell.ps_list->size == 1)
		execute_single_cmdline();
	else
		execute_pipeline();
}
