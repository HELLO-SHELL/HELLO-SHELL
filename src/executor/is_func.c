/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:15:31 by jimin             #+#    #+#             */
/*   Updated: 2022/08/30 09:12:41 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_argv_null(char **argv)
{
	if (*argv)
		return (FAILURE);
	return (SUCCESS);
}

int	is_heredoc_error(void)
{
	t_process	*ps_curr;
	t_token		*cmd_curr;
	size_t		count;

	count = 0;
	ps_curr = g_minishell_info.ps_list;
	while (ps_curr)
	{
		cmd_curr = ps_curr->cmd_line;
		while (cmd_curr)
		{
			if (cmd_curr->type == TK_HEREDOC)
				count++;
			cmd_curr = cmd_curr->next;
		}
		ps_curr = ps_curr->next;
	}
	if (count < 16)
		return (FALSE);
	return (TRUE);
}

static char	*get_accessable_joined_command(const char *command, char **paths)
{
	char	*path_command;
	char	*tmp;
	int		file_type;

	if (paths == NULL)
		return (NULL);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		path_command = ft_strjoin(tmp, command);
		free(tmp);
		tmp = 0;
		file_type = check_file_type(path_command);
		if (file_type == DIRECTORY)
			error_two_exit_status(126, ft_strdup(command), ": is a directory");
		else if (file_type == COMMON_FILE)
			return (path_command);
		free(path_command);
		path_command = NULL;
		paths++;
	}
	return (NULL);
}

char	*get_accessable_command(const char *command, char **paths)
{
	char	*path_command;
	int		file_type;

	path_command = NULL;
	if (ft_strchr(command, '/'))
	{
		file_type = check_file_type(command);
		if (file_type == DIRECTORY)
			error_two_exit_status(126, ft_strdup(command), ": is a directory");
		else if (file_type == NOTFOUND)
			error_two_exit_status(127, (char *) command, \
					": No such file or directory");
		else
		{
			if (access(command, X_OK) == 0)
				return ((char *) command);
			else
				error_two_exit_status(126, (char *) command, \
						": Permission denied");
		}
	}
	else
		path_command = get_accessable_joined_command(command, paths);
	return (path_command);
}
