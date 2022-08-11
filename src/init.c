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
		if (!ft_strchr(input, '$'))
		{
			input_buffer = safe_malloc(ft_strlen(input));
			ft_strlcpy(input_buffer, input, ft_strlen(input) + 1);
		}
		else
		{
			input_buffer = safe_malloc(ft_strlen(input) + 1024);
			ft_strlcpy(input_buffer, input, ft_strchr(input, '$') - input);
		}
		char *head = input_buffer;
		while (*input_buffer)
		{
			if (*input_buffer == '$')
			{
				input_buffer++;	
				*input_buffer = 'R';
			}
			input_buffer++;
		}
		printf("%s debug: %s %s\n", MAG, head, COLOR_RESET);
		str = command_split(input);
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
