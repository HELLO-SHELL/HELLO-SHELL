/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:05:40 by jimin             #+#    #+#             */
/*   Updated: 2022/09/01 16:53:49 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	execute_minishell(char *input)
{
	t_token		*curr_token;
	char		*replaced_input;
	char		**splited_input;

	replaced_input = replace_whole_input_dollar(input);
	if (replaced_input && *replaced_input)
	{
		splited_input = command_split(replaced_input);
		if (!splited_input || !*splited_input)
		{
			free(splited_input);
			return ;
		}
		curr_token = make_token_list(splited_input);
		if (check_token_error(curr_token))
			return ;
		set_process_list(&g_minishell_info.ps_list, curr_token);
		make_node_to_envp();
		executor();
		free_all();
		unlink_all_tempfiles();
	}
	else
		free(replaced_input);
}

void	init_minishell(void)
{
	char		*input;

	while (1)
	{
		signal(SIGINT, get_new_prompt);
		signal(SIGQUIT, SIG_IGN);
		input = readline("HELLO-SHELL-0.0$ :");
		if (!input)
			exit(ft_atoi(g_minishell_info.last_status));
		add_history(input);
		if (quote_validator(input))
			execute_minishell(input);
		else
			free(input);
	}
}
