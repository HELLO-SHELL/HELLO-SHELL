#include "../include/minishell.h"

void    init_minishell(t_minishell *minishell)
{
	t_token		*curr;
	char		*input;
	char		*input_buffer;
	char		**str;
	int			i = 0;
	t_process	*ps_list;

	while(1)
	{
		signal(SIGINT, get_new_prompt);
		signal(SIGQUIT, SIG_IGN);
		ps_list = NULL;
		input = readline("HELLO-SHELL-0.0$ ");
		if (!input)
			exit(EXIT_SUCCESS);
		input_buffer = replace_whole_input_dollar(input, minishell);
		str = command_split(input_buffer);
		minishell->ps_list->cmd_line = set_token_list(str);
		curr = minishell->ps_list->cmd_line;
		add_history(input);
		set_process_list(&ps_list, minishell->ps_list->cmd_line);
		if (input_buffer)
			executor(minishell);
		else
			break ;
		// system("leaks minishell");
		free(input);
	}
}
