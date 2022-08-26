#include "../../../include/minishell.h"

int	check_cmd(char *word)
{
	if (is_same_string(word, CD)
		|| is_same_string(word, ENV)
		|| is_same_string(word, PWD)
		|| is_same_string(word, EXIT)
		|| is_same_string(word, ECHO)
		|| is_same_string(word, UNSET)
		|| is_same_string(word, EXPORT)
		)
		return (1);
	return (0);
}

int	is_built_in(t_process *ps_info)
{
	char *word;

	word = ps_info->cmd_line->value;
	if (check_cmd(word))
		return (1);
	return (0);
}

void	execute_built_in(t_process *process)
{
	char *cmd;

	cmd = process->cmd_line->value;
	if (is_same_string(cmd, CD))
		ft_cd();
	else if (is_same_string(cmd, PWD))
		ft_pwd();
	else if (is_same_string(cmd, ENV))
		ft_env();
	else if (is_same_string(cmd, EXPORT))
		ft_export(process->cmd_line);
	else if (is_same_string(cmd, EXIT))
		ft_exit();
	else if (is_same_string(cmd, UNSET))
		ft_unset();
	else if (is_same_string(cmd, ECHO))
		ft_echo();
	return ;
}