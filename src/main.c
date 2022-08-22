#include "../include/minishell.h"

t_minishell	g_minishell;

int main(int ac, char **av, char **env)
{
	print_wallpaper();
	env_linked_list(env);
	init_minishell();
	return (0);
}
