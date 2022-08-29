/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:58:30 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 16:58:31 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	print_arg_with_idx(char **argv, int idx)
{
	int		flag;

	flag = 0;
	flag = idx;
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

static void	check_option_and_find_print_position(char **argv, int *idx)
{
	int		i;

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

int	ft_echo(char **argv)
{
	int		idx;

	idx = 1;
	check_option_and_find_print_position(argv, &idx);
	print_arg_with_idx(argv, idx);
	return (EXIT_SUCCESS);
}
