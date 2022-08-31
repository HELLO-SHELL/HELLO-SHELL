/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:15:47 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/31 11:57:26 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	safe_free(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
	return ;
}

static void	free_envp(t_process *ps_list)
{
	char	**envp_curr;
	char	**path_curr;
	int		envp_idx;
	int		path_idx;

	envp_curr = ps_list->envp;
	path_curr = ps_list->paths;
	envp_idx = 0;
	path_idx = 0;
	while (envp_curr && envp_curr[envp_idx])
	{
		safe_free(envp_curr[envp_idx]);
		envp_idx++;
	}
	safe_free(envp_curr);
	while (path_curr && path_curr[path_idx])
	{
		safe_free(path_curr[path_idx]);
		path_idx++;
	}
	safe_free(path_curr);
}

static void	free_argv(t_process *ps_list)
{
	char	**argv_curr;
	int		argv_idx;

	argv_curr = ps_list->argv;
	argv_idx = 0;
	while (argv_curr[argv_idx])
	{
		safe_free(argv_curr[argv_idx]);
		argv_idx++;
	}
	safe_free(argv_curr);
}

void	free_token_list(t_token *token)
{
	t_token	*temp_token;
	t_token	*curr_token;

	curr_token = token;
	while (curr_token)
	{
		temp_token = curr_token;
		curr_token = curr_token->next;
		safe_free(temp_token->value);
		temp_token->value = NULL;
		safe_free(temp_token);
	}
}

void	free_all(void)
{
	t_token		*temp_token;
	t_token		*curr_token;
	t_process	*curr_process;
	t_process	*temp_process;

	curr_process = g_minishell_info.ps_list;
	while (curr_process && curr_process->cmd_line)
	{
		temp_process = curr_process;
		curr_process = curr_process->next;
		curr_token = temp_process->cmd_line;
		while (curr_token)
		{
			safe_free(curr_token->value);
			curr_token->value = NULL;
			temp_token = curr_token;
			curr_token = curr_token->next;
			safe_free(temp_token);
			temp_token = NULL;
		}
		free_envp(temp_process);
		free_argv(temp_process);
		safe_free(temp_process);
		temp_process = NULL;
	}
}
