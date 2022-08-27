#include "../include/minishell.h"

t_minishell	g_minishell_info;

void	init_minishell_info(void)
{
	g_minishell_info.env_list = NULL;
	g_minishell_info.last_status = ft_itoa(0);
	init_pipe(&g_minishell_info.pipes);
	g_minishell_info.ps_list = NULL;
	g_minishell_info.heredoc_cnt = 0;
}

int	main(int ac, char **av, char **env)
{
	print_wallpaper();
	init_minishell_info();
	env_linked_list(env);
	g_minishell_info.ft_stdin = dup(STDIN_FILENO);
	g_minishell_info.ft_stdout = dup(STDOUT_FILENO);
	g_minishell_info.ft_stderr = dup(STDERR_FILENO);
	init_minishell();
	return (0);
}
