#include "../../include/minishell.h"

char	*get_accessable_command(t_token *cmd_list, char **paths)
{
	t_token	*curr;
	char	*tmp;
	char	*command;

	while (curr->type == TK_COMMAND)
		curr = curr->next;

	if (!access(command, 0))
		return (command);
	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, command);
		free(tmp);
		tmp = 0;
		if (!access(command, 0))
			return (command);
		free(command);
		command = 0;
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
