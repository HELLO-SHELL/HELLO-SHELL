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
		ft_env(g_minishell_info.env_list);
	else if (is_same_string(cmd, EXPORT))
		ft_export();
	else if (is_same_string(cmd, EXIT))
		ft_exit();
	else if (is_same_string(cmd, UNSET))
		ft_unset();
	else if (is_same_string(cmd, ECHO))
		ft_echo();
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

int	execute_process(t_process *process, t_pipes *pipes)
{
	if (apply_redirections(process->cmd_line) == FAILURE)
		return (FAILURE);
	safe_dup2(pipes->prev_pipe[READ], STDIN_FILENO);
	safe_dup2(pipes->next_pipe[WRITE], STDOUT_FILENO);
	safe_close_pipes(pipes);
	if (is_built_in(process))
		execute_built_in(process);
	else
		execute_command(process);
	return (SUCCESS);
}

void	execute_pipeline(void)
{
	int			idx;
	t_process	*ps_curr;

	idx = 0;
	ps_curr = g_minishell_info.ps_list;
	init_pipe(&g_minishell_info.pipes);
	while (ps_curr)
	{
		swap_pipe(&g_minishell_info.pipes);
		if (ps_curr->next != NULL)
		{
			if (pipe(g_minishell_info.pipes.next_pipe) == -1)
				ft_error_exit("fail_pipe()");
		}
		ps_curr->pid = fork();
		if (ps_curr->pid == -1)
			ft_error_exit("fail fork()\n");
		else if (ps_curr->pid == 0)
			execute_process(ps_curr, &(g_minishell_info.pipes));
		else
		{
			safe_close_pipe(&g_minishell_info.pipes.prev_pipe[READ]);
			safe_close_pipe(&g_minishell_info.pipes.next_pipe[WRITE]);
		}
		ps_curr = ps_curr->next;
	}
	free(g_minishell_info.last_status);
	g_minishell_info.last_status = ft_itoa(wait_childs());
}

int	execute_single_cmdline(void)
{
	pid_t		pid;
	t_process	*process;

	process = g_minishell_info.ps_list;
	if (apply_redirections(process->cmd_line) == FAILURE)
		return (FAILURE);
	if (is_built_in(process))
		execute_built_in(process);
	else
	{
		pid = fork();
		if (pid == 0)
			execute_command(process);
		else
		{
			free(g_minishell_info.last_status);
			g_minishell_info.last_status = ft_itoa(wait_child(pid));
		}
	}
	return (SUCCESS);
}

void	executor(void)
{
	//heredoc_to_temp_files();
	if (g_minishell_info.ps_list->size == 1)
		execute_single_cmdline();
	else
		execute_pipeline();
	restore_stdio();
}
