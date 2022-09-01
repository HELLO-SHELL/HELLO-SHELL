/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:16:24 by jimin             #+#    #+#             */
/*   Updated: 2022/09/01 17:12:19 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	restore_stdio(void)
{
	dup2(g_minishell_info.ft_stdin, STDIN_FILENO);
	dup2(g_minishell_info.ft_stdout, STDOUT_FILENO);
	dup2(g_minishell_info.ft_stderr, STDERR_FILENO);
}

static int	apply_heredoc(void)
{
	char		filename[7];
	const char	*idx_char = "0123456789abcdef";
	int			fd;

	ft_strlcpy(filename, ".temp.", 7);
	filename[5] = idx_char[g_minishell_info.heredoc_cnt];
	fd = safe_openfile(filename, READ);
	if (fd == -1)
	{
		print_error_message("heredoc error");
		return (fd);
	}
	g_minishell_info.heredoc_cnt++;
	dup2(fd, STDIN_FILENO);
	return (fd);
}

static int	apply_redirection(char *filename, int mode)
{
	int	fd;

	fd = 0;
	if (mode == TK_RDINPUT)
	{
		fd = safe_openfile(filename, READ);
		dup2(fd, STDIN_FILENO);
	}
	else if (mode == TK_RDOUTPUT)
	{
		fd = safe_openfile(filename, WRITE);
		dup2(fd, STDOUT_FILENO);
	}
	else if (mode == TK_APPEND)
	{
		fd = safe_openfile(filename, APPEND);
		dup2(fd, STDOUT_FILENO);
	}
	else if (mode == TK_HEREDOC)
		fd = apply_heredoc();
	if (fd == -1)
		return (FAILURE);
	close(fd);
	return (SUCCESS);
}

int	apply_redirections(t_token *cmd_line)
{
	t_token	*curr;

	curr = cmd_line;
	while (curr != NULL)
	{
		if (curr->type == TK_RDINPUT && \
				apply_redirection(curr->next->value, TK_RDINPUT) == FAILURE)
			return (FAILURE);
		else if (curr->type == TK_RDOUTPUT && \
				apply_redirection(curr->next->value, TK_RDOUTPUT) == FAILURE)
			return (FAILURE);
		else if (curr->type == TK_APPEND && \
				apply_redirection(curr->next->value, TK_APPEND) == FAILURE)
			return (FAILURE);
		else if (curr->type == TK_HEREDOC && \
				apply_redirection(NULL, TK_HEREDOC) == FAILURE)
			return (FAILURE);
		curr = curr->next;
	}
	return (SUCCESS);
}
