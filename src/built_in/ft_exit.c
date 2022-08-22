#include "../../include/minishell.h"


void	ft_exit(int status, char *err_msg) // 추후 minishell 구조체가 확정되면 수정 필요
{
	// argc는 최소 1개 (cmd) => 분기점
	// - argc == 2, 즉 argv 유효 원소가 1개일때
	// - argc > 2 && 첫번째 유효원소가 빈스트링
	// - argc > 2
	// - argc == 1
	if (*err_msg)
		print_error_message(err_msg);
	exit(status);
}
