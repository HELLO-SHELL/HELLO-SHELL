/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:59:25 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 16:59:26 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_minishell	g_minishell_info;

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

int	main(int ac, char **av, char **env)
{
	print_wallpaper();
	init_minishell_info();
	env_linked_list(env);
	init_minishell();
	return (0);
}
