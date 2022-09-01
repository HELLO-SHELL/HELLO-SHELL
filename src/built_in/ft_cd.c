/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:58:12 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/01 17:02:52 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	update_env_pwd(void)
{
	t_env	*change_pwd;

	change_pwd = get_env_by_key("PWD");
	if (!change_pwd)
		return (FAILURE);
	free(change_pwd->value);
	change_pwd->value = NULL;
	change_pwd->value = getcwd(NULL, 0);
	if (!change_pwd->value)
		return (FAILURE);
	return (SUCCESS);
}

static int	set_path(char **path)
{
	t_list	*env_list;
	t_token	*cmd_list;

	env_list = g_minishell_info.env_list;
	cmd_list = g_minishell_info.ps_list->cmd_line->next;
	if (is_path_only_home(cmd_list))
		return (set_path_to_home(path));
	else if (is_path_pass_home(cmd_list))
		return (set_path_at_home(cmd_list, path));
	else
		return (set_path_to_input(cmd_list, path));
	return (SUCCESS);
}

static int	change_directory(char **path)
{
	if (chdir(*path) != 0)
	{
		print_error_message("hello-shell: cd: No such file or directory");
		return (FAILURE);
	}
	return (SUCCESS);
}

int	ft_cd(void)
{
	char	*path;

	path = NULL;
	if (!set_path(&path))
		return (EXIT_FAILURE);
	if (!change_directory(&path))
		return (EXIT_FAILURE);
	if (!update_env_pwd())
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
