/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:09:35 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:42:30 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	get_new_prompt(int input)
{
	(void) input;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	heredoc_new_prompt(int input)
{
	(void) input;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	exit(EXIT_FAILURE);
}
