#include "../../../include/minishell.h"

void	safe_free(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
	return ;
}

void free_envp()
{
	char	**envp_curr;
	char	**path_curr;
	int		envp_idx;
	int		path_idx;

	envp_curr = g_minishell_info.ps_list->envp;
	path_curr = g_minishell_info.ps_list->paths;
	envp_idx = 0;
	path_idx = 0;
	while (envp_curr && envp_curr[envp_idx])
	{
		safe_free(envp_curr[envp_idx]);
		envp_idx++;
	}
	safe_free(envp_curr);
	while (path_curr && path_curr[path_idx])
	{
		safe_free(path_curr[path_idx]);
		path_idx++;
	}
	safe_free(path_curr);
}

void free_argv()
{
	char	**argv_curr;
	int		argv_idx;

	argv_curr = g_minishell_info.ps_list->argv;
	argv_idx = 0;
	while (argv_curr[argv_idx])
	{
		safe_free(argv_curr[argv_idx]);
		argv_idx++;
	}
	safe_free(argv_curr);
}

void free_all(char *replaced_input, char **splitted_input)
{
	int			i;
	t_token		*temp_token;
	t_token 	*curr_token;
	t_process	*curr_process;
	t_process	*temp_process;

	safe_free(replaced_input);
	if (!(*replaced_input))
		return ;
	i = -1;
	while (splitted_input[++i])
		safe_free(splitted_input[i]);
	safe_free(splitted_input);
	free_envp();
	free_argv();
	curr_process = g_minishell_info.ps_list;
	while (curr_process && curr_process->cmd_line)
	{
		temp_process = curr_process;
		curr_process = curr_process->next;
		curr_token = temp_process->cmd_line;
		while (curr_token)
		{
			safe_free(curr_token->value);
			curr_token->value = NULL;
			temp_token = curr_token;
			curr_token = curr_token->next;
			safe_free(temp_token);
			temp_token = NULL;
		}
		safe_free(temp_process);
		temp_process = NULL;
	}
}