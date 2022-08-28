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

char	*get_accessable_command(t_token *cmd_list, char **paths)
{
	t_token	*curr;
	char	*tmp;
	char	*command;
	char	*path_command;

	curr = cmd_list;
	while (curr && curr->type != TK_WORD)
		curr = curr->next;
	command = curr->value;
	if (!access(command, 0))
		return (ft_strdup(command));
	if (paths == NULL)
		return (NULL);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		path_command = ft_strjoin(tmp, command);
		free(tmp);
		tmp = 0;
		if (!access(path_command, 0))
			return (path_command);
		free(path_command);
		path_command = NULL;
		paths++;
	}
	return (NULL);
}

int	is_accessable_command(t_token *cmd_list, char **paths)
{
	if (get_accessable_command(cmd_list, paths))
		return (TRUE);
	else
		return (FALSE);
}
