#include "../../include/minishell.h"
#include <stdlib.h>

void	make_temp_file(int file_index, char *delim)
{
	char		*line;
	int			fd;
	char		filename[8];
	const char	*idx_char = "0123456789abcdef";

	ft_strlcpy(filename, ".temp.", 7);
	filename[6] = idx_char[file_index];
	fd = safe_openfile(filename, WRITE);
	line = readline("HereDoc> ");
	while (is_same_string(line, delim) == FALSE)
	{
		line = replace_whole_input_dollar(line);
		ft_putstr_fd(line, fd);
		ft_putstr_fd("\n", fd);
		free(line);
		line = readline("HereDoc> ");
	}
	close(fd);
	free(line);
	line = NULL;
}

int	heredoc_to_temp_files(void)
{
	int			pid;
	t_process	*ps_curr;
	t_token		*cmd_curr;
	char		*delim;
	int			idx;
	
	idx = 0;
	pid = fork();
	ps_curr = g_minishell_info.ps_list;
	if (pid == -1)
		ft_error_exit("fork error");
	else if (pid > 0)
	{
		signal(SIGINT, SIG_IGN);
		return (wait_child(pid));
	}
	else
	{
		signal(SIGINT, heredoc_new_prompt);
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
		exit(EXIT_SUCCESS);
	}
	return (0);
}
