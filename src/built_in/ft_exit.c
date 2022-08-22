#include "../../include/minishell.h"

void	ft_exit(int status, char *err_msg) // 추후 minishell 구조체가 확정되면 수정 필요
{
	// argc 1개 일 때 -> exit -> exit 출력하면서 종료
	// argc 2개 일 때 
	// 문자, 문자+숫자(특수문자..?) helloshell: exit: 문자열: numeric argument required 출력 하고 종료
	// 문자, 문자+숫자일때 argc 3개 이상이면 helloshell: exit: 문자열(첫번째 인자): numeric argument required 출력 하고 종료
	// 숫자이면, exit 출력하면서 종료 echo $? 하면 종료 상태값 저장

	// argc 3개 이상
	// 첫번째 인자가 숫자이면, helloshell: exit: too many argumnents 출력하고 종료x 
	if (*err_msg)
		print_error_message(err_msg);
	exit(status);
}
