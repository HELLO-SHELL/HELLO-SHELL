#include "../../include/minishell.h"

static void	print_arg_with_idx(int idx)
{
	int		flag;
	char	**argv;

	flag = 0;
	flag = idx;
	argv = g_minishell_info.ps_list->argv;
	while (argv[idx])
	{
		ft_putstr_fd(argv[idx], 1);
		if (argv[idx + 1] != NULL)
			ft_putchar_fd(' ', 1);
		idx++;
	}
	if (flag == 1)
		ft_putchar_fd('\n', 1);
}

static void	check_option_and_find_print_position(int *idx)
{
	int		i;
	char	**argv;

	argv = g_minishell_info.ps_list->argv;
	while (argv[*idx])
	{
		i = 0;
		if (argv[*idx][i] == '-')
		{
			i++;
			while (argv[*idx][i] == 'n')
				i++;
			if (argv[*idx][i - 1] != 'n' || argv[*idx][i] != '\0')
				return ;
		}
		else
			return ;
		*idx += 1;
	}
}

int	ft_echo(void)
{
	int		idx;

	idx = 1;
	check_option_and_find_print_position(&idx);
	print_arg_with_idx(idx);
	return (SUCCESS);
}
