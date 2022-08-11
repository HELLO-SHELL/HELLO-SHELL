#include "../include/minishell.h"

void    init_minishell(t_node *minishell)
{
	t_token		*curr;
	char		*input;
	char		*input_buffer;
	char		**str;

	t_pslist	*cmd_lst;

	while(1)
	{
		signal(SIGINT, get_new_prompt);
		signal(SIGQUIT, SIG_IGN);
		input = readline("HELLO-SHELL-0.0$ ");
		if (!input)
			exit(EXIT_SUCCESS);
		input_buffer = replace_whole_input_dollar(input, minishell);
		str = command_split(input_buffer);
		minishell->token_list = set_token_list(str);
		curr = minishell->token_list;
		if (input)
		{
			if (is_same_string(input, ENV))
				ft_env(minishell->env_list);
			else if (is_same_string(curr->value, EXPORT))
				ft_export(minishell);
			else
			{
				write(2,"HELLO-SHELL: ", 13);
				write(2, input, ft_strlen(input));
				write(2, ": command not found\n", 21);
			}
		}
		else
			break ;
		// system("leaks minishell");
		add_history(input);
		set_command_list(&cmd_lst, minishell->token_list);
		free(input);
	}
}