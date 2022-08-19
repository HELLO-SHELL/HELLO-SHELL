#include "../include/minishell.h"

void    init_minishell(void)
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
		replaced_input = replace_whole_input_dollar(input);
		printf("%s%s%s\n", GRN,replaced_input,COLOR_RESET);
		if (replaced_input) 
		{
			if (*replaced_input)
			{
				splitted_input = command_split(replaced_input);
				curr_token = make_token_list(splitted_input);
				set_process_list(&minishell.ps_list, curr_token);
				// executor(minishell);
			}
		}
		else
			break ;
		free_all(replaced_input, splitted_input);
	}
}
