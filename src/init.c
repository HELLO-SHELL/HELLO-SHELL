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
		printf("%s%s%s\n", GRN,replaced_input,COLOR_RESET);
		if (replaced_input)
		{
			if (*replaced_input)
			{
				splitted_input = command_split(replaced_input);
				curr_token = make_token_list(splitted_input);
				set_process_list(&(minishell->ps_list), curr_token);
				// minishell->ps_list->cmd_line = curr_token; //  필요없는 코드로 판단. 필요없는게 맞다면 주석 지워주길 바람.(작성하신 분이). seongyle
				// executor(minishell); wait 추가되야  함.
			}
		}
		else
			break ;
		free_all(minishell, replaced_input, splitted_input);
		// system("leaks minishell");
	}
}
