#include "../../include/minishell.h"

void	execute_command(t_token *head);
void	execute_built_in(t_token *head);
void	execute_pipeline(t_process *ps_list)
{
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

void	execute_single_cmdline(t_token *head)
{
	apply_redirections(head);
	if (is_built_in(head))
		execute_built_in(head);
	else
		execute_command(head);
}

void	executor(t_process *ps_list)
{
	heredoc_to_temp_files(ps_list);
	if (ps_list->size == 1)
		execute_single_cmdline(ps_list->head);
	else
		execute_pipeline(ps_list);
}

