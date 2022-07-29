#include "../include/minishell.h"

int	main(void)
{
	// printf("\n %s: ft_exit unit test : %s \n", MAG, COLOR_RESET);
	// ft_exit(3);

	printf("\n %s: ft_pwd unit test : %s \n", MAG, COLOR_RESET);
	ft_pwd();

	// printf("\n %s: ft_env unit test : %s \n", MAG, COLOR_RESET);
	// ft_env(someting args);
	
	printf("\n%sleak check%s\n", YEL, COLOR_RESET);
	system("leaks unit_test");
}