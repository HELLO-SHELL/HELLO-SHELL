/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:58:50 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/30 09:16:56 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	exit_with_no_param(int ac)
{
	if (ac == 1)
	{
		ft_putendl_fd(EXIT, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
}

int	ft_exit(void)
{
	char	**argv;
	int		ac;

	argv = g_minishell_info.ps_list->argv;
	ac = 0;
	while (argv[ac] != NULL)
		ac++;
	exit_with_no_param(ac);
	if (is_digit_string(argv[1]) && ac == 2)
	{
		ft_putendl_fd(EXIT, STDOUT_FILENO);
		exit((unsigned char) ft_atoi(argv[1]));
	}
	if (is_digit_string(argv[1]) && ac > 2)
	{
		print_error_message("helloshell: exit: too many arguments");
		return (EXIT_FAILURE);
	}
	ft_putstr_fd("helloshell: exit: ", STDERR_FILENO);
	ft_putstr_fd(argv[1], STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	exit(EXIT_255);
}
