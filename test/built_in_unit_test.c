#include "../include/minishell.h"

int	main(void)
{
	// printf("\n %s: ft_exit unit test : %s \n", MAG, COLOR_RESET);
	// ft_exit(7, "");

	// printf("\n %s: ft_pwd unit test : %s \n", MAG, COLOR_RESET);
	// ft_pwd();

	printf("\n %s: ft_env unit test : %s \n", MAG, COLOR_RESET);
	ft_echo();
	
	printf("\n%sleak check%s\n", YEL, COLOR_RESET);
	system("leaks unit_test");
}


// int main()
// {
// 	char *str = "aa bb c ";
// 	echo(str);
// 	ft_putstr_fd("+++++++++++++++++", 1);

// 	char *str1 = "-n aa bb c ";
// 	echo(str1);
// 	ft_putstr_fd("+++++++++++++++++", 1);

// 	char *str2 = "----n aa bb c ";
// 	echo(str2);
// 	ft_putstr_fd("+++++++++++++++++", 1);

// 	char *str3 = "-nnnnnn aa bb c ";
// 	echo(str3);
// 	ft_putstr_fd("+++++++++++++++++", 1);

// 	char *str4 = "------n -nnn -n aa bb cc";
// 	echo(str4);
// 	ft_putstr_fd("+++++++++++++++++", 1);

// 	char *str5 = "-n -n -n -n ---n aa bb c";
// 	echo(str5);
// 	ft_putstr_fd("+++++++++++++++++", 1);

// 	char *str6 = "-nnn -nnn aa bb c ";
// 	echo(str6);
// 	ft_putstr_fd("+++++++++++++++++", 1);
// }