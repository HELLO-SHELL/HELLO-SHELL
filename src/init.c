#include "../include/minishell.h"

void    init_minishell(t_minishell *minishell)
{
	t_token		*curr;
	char		*input;
	char		*input_buffer;
	char		**splitted_input;
	int			i = 0;
	t_process	*ps_list;

	while(1)
	{
		signal(SIGINT, get_new_prompt);
		signal(SIGQUIT, SIG_IGN);
		ps_list = NULL;
		input = readline("HELLO-SHELL-0.0$ :");
		if (!input)
			exit(EXIT_SUCCESS);
		add_history(input);
		input_buffer = replace_whole_input_dollar(input, minishell);
		splitted_input = command_split(input_buffer);
		curr = set_token_list(splitted_input);
		set_process_list(&ps_list, minishell->ps_list->cmd_line);
		minishell->ps_list->cmd_line = curr;
		if (input_buffer)
			// executor(minishell); wait 추가되야  함.
			printf("%s \n", input_buffer); // exexutor 수정 후 executor로 대체 예정
		else
			break ;
		free(input_buffer);
		i = -1;
		while (splitted_input[++i])
			free(splitted_input[i]);
		free(splitted_input);
		splitted_input = NULL;
		t_token *temp;
		while (curr)
		{
			temp = curr;
			free(temp);
			curr = curr->next;
		}
	}
}
