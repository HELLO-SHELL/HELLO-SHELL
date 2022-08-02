#include "../../include/minishell.h"

int	ft_exit(int status)
{
	char *err_msg;

	err_msg = "error message";
	write(2, RED, ft_strlen(RED));
	write(2, err_msg, ft_strlen(err_msg));
	write(2, COLOR_RESET, ft_strlen(COLOR_RESET));
	exit(status);
	return (0);
}
