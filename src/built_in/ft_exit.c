#include "../../include/minishell.h"

static int	is_digit_string(char *check)
{
	int	i;

	i = 0;
	if (check[i] == '\0')
		return (0);
	else if (check[i] == '-' || check[i] == '+')
		i++;
	while (check[i] != '\0')
	{
		if (!ft_isdigit(check[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(void)
{
	char	**argv;
	int		ac;

	argv = g_minishell.ps_list->argv;
	ac = 0;
	while (argv[ac] != NULL)
		ac++;
	if (ac == 1)
	{
		ft_putendl_fd(EXIT, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	if (is_digit_string(argv[1]))
	{
		if (ac == 2)
		{
			ft_putendl_fd(EXIT, STDOUT_FILENO);
			exit(ft_atoi(argv[1]));
		}
		else
			print_error_message("helloshell: exit: too many arguments");
		return ;
	}
	ft_putstr_fd("helloshell: exit: ", STDERR_FILENO);
	ft_putstr_fd(argv[1], STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	exit(EXIT_255);
}
