#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
	char		*input;
	t_token		*token_list;
	t_cmdlst	*cmd_lst;

	print_wallpaper(); 
	while(1)
	{
		input = readline("HELLO-SHELL-0.0$ ");
		if (input)
			printf("%s$\n", input);
		else
			break ;
		add_history(input);
		token_list = set_token_list(command_split(input));
		set_command_list(&cmd_lst, token_list);
		// token list print test
		// while(token_list)
		// {
		// 	printf("%s$\n", token_list->value);
		// 	token_list = token_list->next;
		// }
		// cmd list print test
		while (cmd_lst)
		{
			while (cmd_lst->value->head)
			{
				printf("%s$\n", cmd_lst->value->head->value);
				cmd_lst->value->head = cmd_lst->value->head->next;
			}
			cmd_lst = cmd_lst->next;
		}

		free(input);
	}
	return (0);
}