/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:00:08 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/01 17:01:53 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	is_path_only_home(t_token *cmd_list)
{
	if (cmd_list == NULL
		|| (cmd_list->value[0] == '~' && cmd_list->value[1] == '\0')
		|| (cmd_list->value[0] == '~' && cmd_list->value[1] == '/'
			&& cmd_list->value[2] == '\0'))
		return (1);
	return (0);
}

int	is_path_pass_home(t_token *cmd_list)
{
	if (cmd_list->value[0] == '~' && cmd_list->value[1] == '/')
		return (1);
	return (0);
}

int	set_path_to_home(char **path)
{
	*path = get_env_value_by_key("HOME");
	if (!*path)
		return (FAILURE);
	return (SUCCESS);
}

int	set_path_at_home(t_token *cmd_list, char **path)
{
	*path = get_env_value_by_key("HOME");
	if (chdir(*path) != 0)
	{
		print_error_message("hello-shell: cd: No such file or directory");
		return (FAILURE);
	}
	*path = NULL;
	*path = ft_strchr(cmd_list->value, '/') + 1;
	return (SUCCESS);
}

int	set_path_to_input(t_token *cmd_list, char **path)
{
	*path = cmd_list->value;
	if (!*path)
		return (FAILURE);
	return (SUCCESS);
}
