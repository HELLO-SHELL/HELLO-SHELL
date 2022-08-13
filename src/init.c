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
		input = readline("HELLO-SHELL-0.0$ DEBUG ");
		if (!input)
			exit(EXIT_SUCCESS);
		input_buffer = replace_whole_input_dollar(input, minishell);
		str = command_split(input_buffer);
		minishell->ps_list.cmd_line = set_token_list(str);
		curr = minishell->ps_list.cmd_line;
		add_history(input);
		if (input_buffer)
			executor(minishell);
		else
			break ;
		// system("leaks minishell");
		free(input_buffer);
		i = -1;
		while (str[++i])
			free(str[i]);
		free(str);
		str = NULL;
		t_token *temp;
		while (curr)
		{
		t_token	*temp;
		while (curr)
		{
			temp = curr;
			free(temp);
			curr = curr->next;
		}
		// set_process_list(&ps_list, minishell->ps_list.cmd_line);
		system("leaks minishell");
	}
}
