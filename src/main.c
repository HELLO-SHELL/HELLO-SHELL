#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
	char	*input;
	t_token	*token_list;
	char **str;
	int i = 0;

	print_wallpaper(); 
	input = "1 2 3 4 5 6 7 8";
	str = command_split(input);
	token_list = set_token_list(str);
	return(0);
}
