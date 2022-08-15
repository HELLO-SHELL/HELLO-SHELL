#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
	t_minishell	*minishell;

	minishell = safe_malloc(sizeof(t_minishell));
	print_wallpaper(); 
	env_linked_list(minishell, env);
	init_minishell(minishell);
	return (0);
}
