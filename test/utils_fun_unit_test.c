#include "../include/minishell.h"

void    _init_minishell(t_node *minishell)
{
	t_token		*curr;
	char		*input;
	char		**str;
	int			i = 0;
	t_process	*ps_list;

	while(1)
	{
	    printf("\n %s: get_env_by_key unit test : %s \n", MAG, COLOR_RESET);
		input = readline("HELLO-SHELL-0.0$ ");
		if (!input)
			exit(EXIT_SUCCESS);
		str = command_split(input);
		minishell->token_list = set_token_list(str);
		curr = minishell->token_list;
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
		free(input);
        printf("\n%sleak check%s\n", YEL, COLOR_RESET);
    	system("leaks unit_test");
	}
}

int main(int ac, char **av, char **env)
{
    t_node  *minishell;

    minishell = (t_node *)malloc(sizeof(t_node));
    if (minishell == 0)
        return (0);
    env_linked_list(minishell, env);
   _init_minishell(minishell);
    return (0);
}

// int	main(int ac, char **av, char **env)
// {
    
//     t_list  *curr;
//     t_node  *minishell;

//     minishell = (t_node *)safe_malloc(sizeof(t_node));
//     env_linked_list(minishell, env);
//     curr = minishell->env_list;
// 	printf("\n %s: get_env_by_key unit test : %s \n", MAG, COLOR_RESET);
    
//     while (curr)
//     {
//         printf("key : %s, value : %s\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
//         curr = curr->next;
//     }

//     printf("\n%sleak check%s\n", YEL, COLOR_RESET);
// 	system("leaks unit_test");
// }