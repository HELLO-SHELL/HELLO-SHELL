#include "../../include/minishell.h"

void	apply_redirection(char *filename, int mode)
{
	int	fd;
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
	// 닫아줘야 할까요? close(filename)
}

void	apply_redirections(t_token *cmd_line)
{
	t_token	*curr;

	curr = cmd_line;
	while (curr != NULL)
	{
		if (curr->type == TK_RDINPUT)
			apply_redirection(curr->next->value, TK_RDINPUT);
		else if (curr->type == TK_RDOUTPUT)
			apply_redirection(curr->next->value, TK_RDOUTPUT);
		else if (curr->type == TK_APPEND)
			apply_redirection(curr->next->value, TK_APPEND);
		curr = curr->next;
	}
}
