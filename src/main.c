#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
	char	*input;
	t_token	*token_list;
	char **str;
	int i = 0;

	print_wallpaper(); 
	while(1)
	{
		input = readline("HELLO-SHELL-0.0$ ");
		if (input)
			printf("%s$\n", input);
		else
			break ;
		add_history(input);
		str = command_split(input);
		token_list = set_token_list(str);
		while(token_list)
		{
			printf("%s$\n", token_list->value);
			token_list = token_list->next;
		}
		free(input);
	}
	return (0);
}