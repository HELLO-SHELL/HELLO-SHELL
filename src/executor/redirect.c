#include "../../include/minishell.h"
#include <unistd.h>

void	restore_stdio(void)
{
	dup2(g_minishell_info.ft_stdin, STDIN_FILENO);
	dup2(g_minishell_info.ft_stdout, STDOUT_FILENO);
	dup2(g_minishell_info.ft_stderr, STDERR_FILENO);
}

int	apply_heredoc(void)
{
	char		filename[8];
	const char	*idx_char = "0123456789abcdef";
	int			fd;

	print_error_two_messages("heredoc_cnt: ", ft_itoa(g_minishell_info.heredoc_cnt));
	ft_strlcpy(filename, ".temp.", 7);
	filename[6] = idx_char[g_minishell_info.heredoc_cnt];
	fd = safe_openfile(filename, READ);
	if (fd == -1)
		ft_error_exit("heredoc file error");
	g_minishell_info.heredoc_cnt++;
	return (fd);
}

int	apply_redirection(char *filename, int mode)
{
	int	fd;

	if (mode == TK_RDINPUT)
		fd = safe_openfile(filename, READ);
	else if (mode == TK_RDOUTPUT)
		fd = safe_openfile(filename, WRITE);
	else if (mode == TK_APPEND)
		fd = safe_openfile(filename, APPEND);
	else if (mode == TK_HEREDOC)
		fd = apply_heredoc();
	if (fd == -1)
		return (FAILURE);
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (SUCCESS);
}

int	apply_redirections(t_token *cmd_line)
{
	t_token	*curr;

	curr = cmd_line;
	while (curr != NULL)
	{
		if (curr->type == TK_RDINPUT &&
				apply_redirection(curr->next->value, TK_RDINPUT) == FAILURE)
			return (FAILURE);
		else if (curr->type == TK_RDOUTPUT &&
				apply_redirection(curr->next->value, TK_RDOUTPUT) == FAILURE)
			return (FAILURE);
		else if (curr->type == TK_APPEND &&
				apply_redirection(curr->next->value, TK_APPEND) == FAILURE)
			return (FAILURE);
		else if (curr->type == TK_HEREDOC && 
				apply_redirection(NULL, TK_HEREDOC) == FAILURE)
			return (FAILURE);
		curr = curr->next;
	}
	return (SUCCESS);
}
