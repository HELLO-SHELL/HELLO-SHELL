#include "../../include/minishell.h"

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
	safe_close_pipes(p);
	if (is_built_in(ps_info->cmd_line))
		execute_built_in(ps_info);
	else
		execute_command(ps_info);
}

void	execute_pipeline(t_node *minishell)
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
			execute_command(ps_curr, minishell->pipes);
		else
		{
			safe_close_pipe(&minishell->pipes.prev_pipe[READ]);
			safe_close_pipe(&minishell->pipes.next_pipe[WRITE]);
		}
		ps_curr = ps_curr->next;
	}
	//pipe 만들고 관리 (jimin_pipex 참조);
	//while (fork 뜨기(총 process 개수)
	//	ps_id
	//  redirection 처리
	//	apply_redirections(ps_list, ps_id);
	//	is_accessable() command 검사 (실행가능한지, built-in 함수인지)
	//	if built-in 함수면
	//		execute_builtin
	//	else if 실행가능하면
	//		execute_command
	//	else
	//		에러 출력
}

void	execute_single_cmdline(t_process *process)
{
	apply_redirections(process->cmd_line);
	if (is_built_in(process))
		execute_built_in(process);
	else
		execute_command(process);
}

void	executor(t_node *minishell)
{
	t_process	*ps_list;

	ps_list = minishell->ps_list;
	heredoc_to_temp_files(ps_list);
	if (ps_list->size == 1)
		execute_single_cmdline(ps_list);
	else
		execute_pipeline(minishell);
}
