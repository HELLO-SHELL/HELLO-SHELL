#include "../include/minishell.h"

void	init_minishell(void)
{
	t_token		*curr_token;
	char		*input;
	char		*replaced_input;
	char		**splitted_input;

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
				splitted_input = command_split(replaced_input);
				curr_token = make_token_list(splitted_input);
				set_process_list(&g_minishell_info.ps_list, curr_token);
				make_node_to_envp();
				executor();
				printf("last_status: %s\n", g_minishell_info.last_status);
				free_all(replaced_input, splitted_input);
				printf("last_status: %s\n", g_minishell_info.last_status);
			}
		}
		else
			free(input);
	}
}
