/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:59:25 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/01 17:24:57 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_minishell	g_minishell_info;

int	check_main_input(int argc, char **argv)
{
	if (argc != 1)
	{
		print_error_message("Usage: ./minishell");
		return (1);
	}
	if (argv[0] == NULL)
	{
		print_error_message("Impossible Error");
		return (1);
	}
	return (0);
}

void	init_minishell_info(void)
{
	g_minishell_info.env_list = NULL;
	g_minishell_info.last_status = ft_itoa(0);
	init_pipe(&g_minishell_info.pipes);
	g_minishell_info.ps_list = NULL;
	g_minishell_info.heredoc_cnt = 0;
	g_minishell_info.ft_stdin = dup(STDIN_FILENO);
	g_minishell_info.ft_stdout = dup(STDOUT_FILENO);
	g_minishell_info.ft_stderr = dup(STDERR_FILENO);
}

int	main(int argc, char **argv, char **envp)
{
	if (check_main_input(argc, argv))
		return (1);
	print_wallpaper();
	init_minishell_info();
	env_linked_list(envp);
	init_minishell();
	return (0);
}
