#include "../../include/minishell.h"

void    init_minishell(t_node *minishell)
{
    t_token *curr;
    char    *input;
	char    **str;
	int     i = 0;

    while(1)
    {
        input = readline("HELLO-SHELL-0.0$ ");
        str = command_split(input);
		minishell->token_list = set_token_list(str);
        curr = minishell->token_list;
        if (input)
        {
            // is_same_string(curr->value, ENV)를 하게 되면,
            // env a b 처럼 추가 입력 값이 있어도 true 가 되기 때문에 ft_env에 예외조건 추가 필요
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
        free(input);
    }
}