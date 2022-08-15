#include "../include/minishell.h"

void    init_minishell(t_minishell *minishell)
{
	t_token		*curr_token;
	char		*input;
	char		*replaced_input;
	char		**splitted_input;
	int			i = 0;

	while(1)
	{
		signal(SIGINT, get_new_prompt);
		signal(SIGQUIT, SIG_IGN);
		input = readline("HELLO-SHELL-0.0$ :");
		if (!input)
			exit(EXIT_SUCCESS);
		add_history(input);
		replaced_input = replace_whole_input_dollar(input, minishell);
		if (replaced_input)
		{
			if (*replaced_input)
			{
				splitted_input = command_split(replaced_input);
				curr_token = make_token_list(splitted_input);
				set_process_list(&(minishell->ps_list), curr_token);
				minishell->ps_list->cmd_line = curr_token;
				// executor(minishell); wait 추가되야  함.
			}
		}
		else
			break ;
		free(replaced_input);
		replaced_input = NULL;
		i = -1;
		while (splitted_input[++i])
			free(splitted_input[i]);
		free(splitted_input);
		splitted_input = NULL;
		t_token *temp;
		while (curr_token)
		{
			temp = curr_token;
			free(temp);
			curr_token = curr_token->next;
		}
		t_process	*curr_process;
		t_process	*temp_process;
		curr_process = minishell->ps_list;
		while (curr_process)
		{
			temp_process = curr_process;
			curr_process = curr_process->next;
			free(temp_process);
			temp_process = NULL;
		}
		system("leaks minishell");
	}
}
