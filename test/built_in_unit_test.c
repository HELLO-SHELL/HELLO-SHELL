#include "../include/minishell.h"

int	main(void)
{
	// printf("\n %s: ft_exit unit test : %s \n", MAG, COLOR_RESET);
	// ft_exit(7, "");

	// printf("\n %s: ft_pwd unit test : %s \n", MAG, COLOR_RESET);
	// ft_pwd();

	printf("\n %s: ft_env unit test : %s \n", MAG, COLOR_RESET);

	char *str = "echo aa bb c";
	ft_echo(&str);
	ft_putstr_fd("\n1+++++++++++++++++\n", 1);

	char *str1 = "echo -n aa bb c ";
	ft_echo(&str1);
	ft_putstr_fd("\n2+++++++++++++++++\n", 1);

	char *str2 = "echo ----n aa bb c ";
	ft_echo(&str2);
	ft_putstr_fd("\n3+++++++++++++++++\n", 1);

	char *str3 = "echo -nnnnnn aa bb c ";
	ft_echo(&str3);
	ft_putstr_fd("\n4+++++++++++++++++\n", 1);

	char *str4 = "echo ------n -nnn -n aa bb cc";
	ft_echo(&str4);
	ft_putstr_fd("\n5+++++++++++++++++\n", 1);

	char *str5 = "echo -n -n -n -n ---n aa bb c";
	ft_echo(&str5);
	ft_putstr_fd("\n6+++++++++++++++++\n", 1);

	char *str6 = "echo -nnn -nnn aa bb c ";
	ft_echo(&str6);
	ft_putstr_fd("\n7+++++++++++++++++\n", 1);
	
	printf("\n%sleak check%s\n", YEL, COLOR_RESET);
	system("leaks unit_test");
}
