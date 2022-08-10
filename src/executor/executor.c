#include "../../include/minishell.h"

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

void	execute_single_cmdline()
{
	//built_in 인지 검사
	//accessable_command 인지 검사
}

void	heredoc_to_tempfiles(t_process *ps_list)
{
	//	fork() 떠서 실행. 이유는 ctrl-C 를 처리하기 위해.
	//	ctrl-C 입력이 들어오면 비정상 종료 시그널 넘기고 파이프라인 실행 종료
	//	다음 shell 입력받을 준비 (prompt 출력)
	//
	//	while ps_list->head 를	
	//		type이 herecoc 이면 next 를 delim으로 받고
	//		temp 파일을 write로 open CREAT 옵션으로 생성하고 open
	//		파일명은 temp 뒤에 뭔가 붙이자
	//		gnl로 delim 나올때까지 temp[i]에 저장
	//		ps_list->curr를 < 로 변경
	//		ps_list->next를 temp숫자로 변경
	//		close
}

void	executor(t_process *ps_list)
{
	// ps_list 에 있는 node를 순회하면서
	// while
	
	// heredoc 처리
	heredoc_to_tempfiles(ps_list);
	
	// 하나만 execute 할 때는 따로 분류합니다.
	// built-in 함수는 그냥 실행
	// pipeline 은 무조건 fork
	// execve 사용하는 실행파일 (ex. ls ..) 은 무조건 fork
	execute_single_cmdline();
	execute_pipeline(ps_list);
}

