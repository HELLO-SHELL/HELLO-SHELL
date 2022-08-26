#include "../include/minishell.h"

void	init_minishell(void)
{
	t_token		*curr_token;
	char		*input;
	char		*replaced_input;

	while (1)
	{
		signal(SIGINT, get_new_prompt);
		signal(SIGQUIT, SIG_IGN);
		input = readline("HELLO-SHELL-0.0$ :");
		if (!input)
			exit(ft_atoi(g_minishell_info.last_status));
		add_history(input);
		if (quote_validator(input))
		{
			replaced_input = replace_whole_input_dollar(input);
			if (replaced_input && *replaced_input)
			{
        curr_token = make_token_list(command_split(replaced_input));
        if (set_process_list(&g_minishell_info.ps_list, curr_token))
          continue;
        make_node_to_envp();
        executor();
        free_all();
        //	system("leaks minishell");
			}
		}
		else
			free(input);
	}
}

void	init_minishell_info(void)
{
	g_minishell_info.env_list = NULL;
	g_minishell_info.last_status = ft_itoa(0);
	init_pipe(&g_minishell_info.pipes);
	g_minishell_info.ps_list = NULL;
	g_minishell_info.heredoc_cnt = 0;
}
