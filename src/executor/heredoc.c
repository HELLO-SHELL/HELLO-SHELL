#include "../../include/minishell.h"

int	openfile(char *filename, int mode)
{
	int	fd;

	fd = -1;
	if (mode == READ)
	{
		if (access(filename, F_OK))
			ft_error_exit(ft_strjoin("No Such File: ", filename));
		else
			fd = open(filename, O_RDONLY);
	}
	else if (mode == WRITE)
		fd = open(filename, O_TRUNC | O_CREAT | O_RDWR, 0644);
	else if (mode == APPEND)
		fd = open(filename,  O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		ft_error_exit(ft_strjoin("No Such File: ", filename));
	return (fd);
}

char 	*get_temp_file_name(int idx)
{
	char		filename[6];
	const char	*idx_char = "0123456789abcdef";

	ft_strlcpy(filename, ".temp.", 6);
	filename[5] = idx_char[idx];
	return (filename);
}

void	make_temp_file(int file_index, char *delim)
{
	char		*line;
	int			fd;

	fd = openfile(get_temp_file_name(file_index), APPEND);
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
	free(cmd_curr->value);
	free(cmd_curr->next->value);
	cmd_curr->value = ft_strdup("<");
	cmd_curr->type = TK_RDINPUT;
	cmd_curr->next->value = get_temp_file_name(idx);
	cmd_curr->next->type = TK_FILE;
}

void	heredoc_to_temp_files(t_process *ps_list)
{
	int			pid;
	t_process	*ps_curr;
	t_token		*cmd_curr;
	char		*delim;
	int			idx;
	
	idx = 0;
	pid = fork();
	// signal 처리
	ps_curr = ps_list;
	if (pid)
		return ;
	while (ps_curr == NULL)
	{
		cmd_curr = ps_list->head;
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
}
