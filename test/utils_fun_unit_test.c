#include "../include/minishell.h"

int	main(int ac, char **av, char **env)
{
    t_node  *minishell;

	print_wallpaper(); 
    minishell = (t_node *)safe_malloc(sizeof(t_node));
    env_linked_list(minishell, env);
	printf("\n %s: get_env_by_key unit test : %s \n", MAG, COLOR_RESET);
    printf("%s", get_env_by_key(minishell->env_list, "PWD")->value);
	printf("\n%sleak check%s\n", YEL, COLOR_RESET);
	system("leaks unit_test");
}