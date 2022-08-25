#include "../include/minishell.h"

t_minishell	g_minishell_info;

int	main(int ac, char **av, char **env)
{
	print_wallpaper();
	init_minishell_info();
	env_linked_list(env);
	init_minishell();
	return (0);
}
