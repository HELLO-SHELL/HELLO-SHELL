/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:15:28 by jimin             #+#    #+#             */
/*   Updated: 2022/09/01 17:11:37 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	make_temp_file(int file_index, char *delim)
{
	char		*line;
	int			fd;
	char		filename[7];
	const char	*idx_char = "0123456789abcdef";

	ft_strlcpy(filename, ".temp.", 7);
	filename[5] = idx_char[file_index];
	fd = safe_openfile(filename, WRITE);
	if (fd == -1)
		error_exit("heredoc file error");
	line = readline("HereDoc> ");
	while (line && is_same_string(line, delim) == FALSE)
	{
		line = replace_dollar_in_heredoc(line);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
		line = readline("HereDoc> ");
	}
	close(fd);
	if (line)
		free(line);
}

static void	heredoc_to_temp_files(void)
{
	t_process	*ps_curr;
	t_token		*cmd_curr;
	char		*delim;
	int			idx;

	idx = 0;
	ps_curr = g_minishell_info.ps_list;
	while (ps_curr != NULL)
	{
		cmd_curr = ps_curr->cmd_line;
		while (cmd_curr != NULL)
		{
			if (cmd_curr->type == TK_HEREDOC)
			{
				delim = cmd_curr->next->value;
				make_temp_file(idx, delim);
				idx++;
			}
			cmd_curr = cmd_curr->next;
		}
		ps_curr = ps_curr->next;
	}
}

void	unlink_all_tempfiles(void)
{
	int			idx;
	char		filename[7];
	const char	*idx_char = "0123456789abcdef";

	idx = 0;
	ft_strlcpy(filename, ".temp.", 7);
	while (idx < 16)
	{
		filename[5] = idx_char[idx];
		if (access(filename, F_OK) == 0)
			unlink(filename);
		idx++;
	}
}

int	execute_heredoc(void)
{
	int		pid;

	g_minishell_info.heredoc_cnt = 0;
	pid = fork();
	if (pid == -1)
		error_exit("fork error");
	else if (pid == 0)
	{
		signal(SIGINT, heredoc_new_prompt);
		heredoc_to_temp_files();
		exit(0);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		set_last_status(wait_child(pid));
		if (is_same_string(g_minishell_info.last_status, "130"))
			return (FAILURE);
	}
	return (SUCCESS);
}
