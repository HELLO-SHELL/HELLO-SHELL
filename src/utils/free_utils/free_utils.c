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

void    free_all(t_minishell *minishell, char *replaced_input, char **splitted_input)
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
	curr_process = minishell->ps_list;
	while (curr_process && curr_process->cmd_line)
	{
		curr_token = curr_process->cmd_line;
		while (curr_token)
		{
			temp_token = curr_token;
			curr_token = curr_token->next;
			safe_free(temp_token);
		}
		temp_process = curr_process;
		curr_process = curr_process->next;
		safe_free(temp_process);
	}
}