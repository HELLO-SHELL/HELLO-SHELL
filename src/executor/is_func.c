#include "../../include/minishell.h"

char	*get_accessable_command(t_token *cmd_list, char **paths)
{
	t_token	*curr;
	char	*tmp;
	char	*command;
	char	*path_command;

	curr = cmd_list;
	while (curr->type != TK_WORD)
		curr = curr->next;
	command = curr->value;
	if (!access(command, 0))
		return (command);
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
	ft_error_exit(ft_strjoin(": command not found", command));
	return (0);
}

int	is_accessable_command(t_token *cmd_list, char **paths)
{
	if (get_accessable_command(cmd_list, paths))
		return (TRUE);
	else
		return (FALSE);
}
