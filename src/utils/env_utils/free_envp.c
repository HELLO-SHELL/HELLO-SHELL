#include "../../../include/minishell.h"

void free_envp()
{
	char	**envp_curr;
	char	**path_curr;
	int		envp_idx;
	int		path_idx;

	envp_curr = g_minishell.ps_list->envp;
	path_curr = g_minishell.ps_list->paths;
	envp_idx = 0;
	path_idx = 0;
	while (envp_curr[envp_idx])
	{
		free(envp_curr[envp_idx]);
		envp_idx++;
	}
	free(envp_curr);
	while (path_curr[path_idx])
	{
		free(path_curr[path_idx]);
		path_idx++;
	}
	free(path_curr);
	// process list의 envp와 path 비우기
}