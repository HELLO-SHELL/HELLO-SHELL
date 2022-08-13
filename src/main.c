#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	print_wallpaper(); 
	minishell = (t_minishell *)malloc(sizeof(t_minishell));
	if (minishell == 0)
			return (0);
	env_linked_list(minishell, env);
	init_minishell(minishell);
	return (0);
}
