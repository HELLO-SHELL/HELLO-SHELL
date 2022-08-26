#include "../../include/minishell.h"

void	set_last_status(int status)
{
	free(g_minishell_info.last_status);
	g_minishell_info.last_status = ft_itoa(status);
}

