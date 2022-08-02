#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
	char		*input;
	t_token		*token_list;
	t_pslist	*cmd_lst;

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
		free(input);
	}
	return (0);
}