#include "../../include/minishell.h"

int	is_argv_null(char **argv)
{
	if (*argv)
		return (FAILURE);
	return (SUCCESS);
}

char	*get_accessable_command(const char *command, char **paths)
{
	t_token	*curr;
	char	*tmp;
	char	*path_command;

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
		if (!access(path_command, X_OK))
			return (path_command);
		free(path_command);
		path_command = NULL;
		paths++;
	}
	return (NULL);
}
