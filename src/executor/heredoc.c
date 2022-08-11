#include "../../include/minishell.h"

void	heredoc_to_temp_files(t_process *ps_list)
{
	//	fork() 떠서 실행. 이유는 ctrl-C 를 처리하기 위해.
	//	ctrl-C 입력이 들어오면 비정상 종료 시그널 넘기고 파이프라인 실행 종료
	//	다음 shell 입력받을 준비 (prompt 출력)
	//	while ps_list->head 를	
	//		type이 herecoc 이면 next 를 delim으로 받고
	//		temp 파일을 write로 open CREAT 옵션으로 생성하고 open
	//		파일명은 temp 뒤에 뭔가 붙이자
	//		gnl로 delim 나올때까지 temp[i]에 저장
	//		ps_list->curr를 < 로 변경
	//		ps_list->next를 temp숫자로 변경
	//		close
}
