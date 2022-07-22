#include "../../include/minishell.h"

int	ft_exit(int status)
{
	printf("%sERROR: error status is %d%s\n", RED, status, COLOR_RESET);
	exit(status);
	return (0);
}
