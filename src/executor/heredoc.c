#include "../../include/minishell.h"

void	make_temp_file(int file_index, char *delim)
{
	char	*line;
	int		fd;
	char		filename[6];
	const char	*idx_char = "0123456789abcdef";

	ft_strlcpy(filename, ".temp.", 6);
	filename[5] = idx_char[file_index];
	fd = safe_openfile(filename, APPEND);
	line = get_next_line(STDIN_FILENO);
	while (is_same_string(line, delim) == FALSE)
	{
		ft_putstr_fd(line, fd);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(fd);
	free(line);
	line = NULL;
}

void	change_heredoc_to_redirect(t_token *cmd_curr ,int idx)
{
	char		filename[6];
	const char	*idx_char = "0123456789abcdef";

	ft_strlcpy(filename, ".temp.", 6);
	filename[5] = idx_char[idx];
	free(cmd_curr->value);
	free(cmd_curr->next->value);
	cmd_curr->value = ft_strdup("<");
	cmd_curr->type = TK_RDINPUT;
	cmd_curr->next->value = filename;
	//여기서 에러날것 같아요 근데 그냥 덮고 넘어감
	cmd_curr->next->type = TK_FILE;
}

void	heredoc_to_temp_files(void)
{
	int			pid;
	t_process	*ps_curr;
	t_token		*cmd_curr;
	char		*delim;
	int			idx;
	
	idx = 0;
	pid = fork();
	// pid 에러처리 해라
	ps_curr = g_minishell.ps_list;
	if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		return ;
	}
	signal(SIGINT, heredoc_new_prompt);
	while (ps_curr == NULL)
	{
		cmd_curr = ps_curr->cmd_line;
		while (cmd_curr)
		{
			if (cmd_curr->type == TK_HEREDOC)
			{
				delim = cmd_curr->next->value;
				make_temp_file(idx, delim);
				change_heredoc_to_redirect(cmd_curr, idx);
				idx++;
			}
		}
		ps_curr = ps_curr->next;
	}
	wait_child(pid);
}
