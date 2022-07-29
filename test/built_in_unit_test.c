#include "../include/minishell.h"

int	main(void)
{
	printf("%s: ft_exit unit test : %s \n", MAG, COLOR_RESET);
	ft_exit(3);
	system("leaks unit_test");
	printf("%sleak check pass%s \n", GRN, COLOR_RESET);
}