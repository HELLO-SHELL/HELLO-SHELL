#include "../../include/minishell.h"

void	execute_command(t_process *process)
{
	get_accessable_command();
	if (info->cmd_m == NULL)
		return (-1);
	return (execve(info->cmd_m, info->cmd_args_m, envp));
}

void	execute_process(t_process *process)
{
	fork();
	apply_redirections(process->cmd_line);
	if (info->ps_id == -1)
		ft_error_exit("fail fork()");
	else if (info->ps_id == 0)
	{
		if (is_built_in(ps_curr->cmd_line))
			execute_built_in(ps_curr->cmd_line);
		else
			execute_command(ps_curr);
	}
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
		else
		{
			close_pipe(&minishell->pipes.prev_pipe[READ]);
			close_pipe(&minishell->pipes.next_pipe[WRITE]);
		}
		idx++;
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

void	execute_single_cmdline(t_token *cmd_line)
{
	apply_redirections(cmd_line);
	if (is_built_in(cmd_line))
		execute_built_in(cmd_line);
	else
		execute_command(int id, t_node *minishell);
}

void	executor(t_node *minishell)
{
	t_process	*ps_list;

	ps_list = minishell->ps_list;
	heredoc_to_temp_files(ps_list);
	if (ps_list->size == 1)
		execute_single_cmdline(ps_list->cmd_line);
	else
		execute_pipeline(minishell);
}

