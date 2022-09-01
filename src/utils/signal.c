/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:00:05 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:25:59 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_new_prompt(int input)
{
	set_last_status(input);
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	heredoc_new_prompt(int input)
{
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	unlink_all_tempfiles();
	exit(input + 128);
}
