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
			printf("%s\n", input);
		else
			break ;
		add_history(input);
		str = command_split(input);
		token_list = init_token_list(str);
		printf("------------------\n");
		// while(token_list)
		// {
		// 	printf("value : %s\n", token_list->value);
		// 	printf("prev : %p\n", token_list->prev);
		// 	printf("next : %p\n", token_list->next);
		// 	printf("type : %d\n", token_list->type);
		// 	printf("me : %p\n", token_list);
		// 	printf("------------------\n");
		// 	token_list = token_list->next;
		// }
		token_list = token_list->next->prev;
		printf("value : %s\n", token_list->value);
		free(input);
	}
	return(0);
}