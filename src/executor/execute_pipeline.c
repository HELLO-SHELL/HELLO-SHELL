#include "../../include/minishell.h"

int	is_acceccable();
void	redirection(t_process *ps_list, int ps_id)
{
	//ps_list 의 ps_id 번째 node 의 head
	//안에 있는 redirection을 찾고
	//file_to_std(openfile(), int mode {<: stdin_fileno >:stdout_fileno })
	//	file_to_std 안애서 dup2 실행하면 된다.
}

void	execute_pipeline(t_process *ps_list)
{
	//pipe 만들고 관리 (jimin_pipex 참조);

	//while (fork 뜨기(총 process 개수)
	//	ps_id
	//	redirection(ps_list, ps_id);
	//	access command 검사 (실행가능한지, built-in 함수인지)
	//	if built-in 함수면
	//		execute_builtin
	//	else if 실행가능하면
	//		execute_command
	//	else
	//		에러 출력

}
	
void	heredoc_to_temp(t_process *ps_list)
{
	//while 문으로 ps_list -> next로 넘기기
	
	//	while ps_list->head 를	
	//		type이 herecoc 이면 next 를 delim으로 받고
	//		temp 파일을 write로 open CREAT 옵션으로 생성하고 open
	//		파일명은 temp 뒤에 뭔가 붙이자
	//		gnl로 delim 나올때까지 temp[i]에 저장
	//		ps_list->curr를 < 로 변경
	//		ps_list->next를 temp숫자로 변경
	//		close
}


int	executor(t_process *ps_list)
{
	// ps_list 에 있는 node를 순회하면서
	
	// heredoc 처리
	heredoc_to_temp(ps_list);
	
	// redirection 처리
	execute_pipeline(ps_list);
	// 돌면서 execute
}

