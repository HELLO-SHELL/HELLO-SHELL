#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    char *input;

    print_wallpaper(); 
    while(1)
    {
        input = readline("HELLO-SHELL-0.0$ ");
        if (input)
        {
            if (is_same_string(input, "exit"))
            {
                free(input);
                ft_exit(1);
            }
            printf("%s\n", input);
        }
        else
            break ;
        add_history(input);
        free(input);
    }
    system("leaks minishell");
    return(0);
}