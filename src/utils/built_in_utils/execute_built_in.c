/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_built_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:03:35 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:03:36 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	check_cmd(char *word)
{
	if (is_same_string(word, CD)
		|| is_same_string(word, ENV)
		|| is_same_string(word, PWD)
		|| is_same_string(word, EXIT)
		|| is_same_string(word, ECHO)
		|| is_same_string(word, UNSET)
		|| is_same_string(word, EXPORT)
	)
		return (1);
	return (0);
}

int	is_built_in(t_process *ps_info)
{
	const char	*command = *ps_info->argv;

	if (check_cmd((char *) command))
		return (1);
	return (0);
}

int	execute_built_in(t_process *process)
{
	char	*cmd;

	cmd = process->cmd_line->value;
	if (is_same_string(cmd, CD))
		return (ft_cd());
	else if (is_same_string(cmd, PWD))
		return (ft_pwd());
	else if (is_same_string(cmd, ENV))
		return (ft_env());
	else if (is_same_string(cmd, EXPORT))
		return (ft_export(process->cmd_line));
	else if (is_same_string(cmd, EXIT))
		return (ft_exit());
	else if (is_same_string(cmd, UNSET))
		return (ft_unset());
	else if (is_same_string(cmd, ECHO))
		return (ft_echo(process->argv));
	return (EXIT_FAILURE);
}
