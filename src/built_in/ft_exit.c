#include "../../include/minishell.h"

void	ft_exit(int status, char *err_msg) // 추후 minishell 구조체가 확정되면 수정 필요
{
	if (*err_msg)
		print_error_message(err_msg);
	exit(status);
}
