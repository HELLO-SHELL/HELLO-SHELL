#include "../include/minishell.h"

void    init_minishell(t_node *minishell)
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
		if (input)
		{
			if (is_same_string(input, ENV))
				ft_env(minishell->env_list);
			else if (is_same_string(curr->value, EXPORT))
				ft_export(minishell);
			else if (is_same_string(curr->value, UNSET))
				ft_unset(minishell);
			else
			{
				write(2,"HELLO-SHELL: ", 13);
				write(2, input, ft_strlen(input));
				write(2, ": command not found\n", 21);
			}
		}
		else
			break ;
		add_history(input);
		set_process_list(&ps_list, minishell->ps_list->cmd_line);
		// heredoc_to_temp_files(ps_list);
		free(input);
		i=-1;
		while (str[++i])
			free(str[i]);
		free(str);
		str = NULL;
		t_token *temp;
		while (curr)
		{
			// free(curr->value);
			temp = curr;
			free(temp);
			curr = curr->next;
		}
		system("leaks minishell");
	}
}
