/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:15:28 by jimin             #+#    #+#             */
/*   Updated: 2022/08/31 01:18:36 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	make_temp_file(int file_index, char *delim)
{
	char		*line;
	int			fd;
	char		filename[8];
	const char	*idx_char = "0123456789abcdef";

	ft_strlcpy(filename, ".temp.", 7);
	filename[6] = idx_char[file_index];
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

int	execute_heredoc(void)
{
	int		pid;
	int		status;

	g_minishell_info.heredoc_cnt = 0;
	pid = fork();
	if (pid == -1)
		error_exit("fork error");
	else if (pid == 0)
	{
		signal(SIGINT, heredoc_new_prompt);
		heredoc_to_temp_files();
		exit(EXIT_SUCCESS);
	}
	else
	{
		signal(SIGINT, SIG_IGN);
		status = wait_child(pid);
		set_last_status(status);
	}
	return (0);
}
