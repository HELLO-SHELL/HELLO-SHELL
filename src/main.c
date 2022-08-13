#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
	t_node	*minishell;

	print_wallpaper(); 
	minishell = (t_node *)malloc(sizeof(t_node));
	if (minishell == 0)
			return (0);
	env_linked_list(minishell, env);
	init_minishell(minishell);
	return (0);
}
