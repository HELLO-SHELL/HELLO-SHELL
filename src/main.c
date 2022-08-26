#include "../include/minishell.h"

t_minishell	g_minishell_info;

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
