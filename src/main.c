#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    t_list  *env_list;
    t_env   *env_contents;
    int i;
    int j;
    int key_length = 0;
    int value_length = 0;

    i = 0;
    while (env[i])
    {
        j = 0;
        env_list = (t_list *)malloc(sizeof(t_list));
        if (env_list == 0)
            return (0);

        env_list->content = (t_env *)malloc(sizeof(t_env));
        if (env_list->content == 0)
            return (0);
        
        while (env[i][j] != '=')
        {
            key_length++;
            j++;
        }
        j++;
        while (env[i][j] != '\0')
        {
            value_length++;
            j++;
        }
        printf("%s\n", env[i]);
        printf("key : %d, value : %d\n", key_length, value_length);
        printf("\n------------------------------------------\n");
        key_length = 0;
        value_length = 0;
        free (env_list->content);
        free (env_list);
        i++;
    }
    /*----------------------------------------------*/
    
    // while(1)
    // {
    //     input = readline("HELLO-SHELL-0.0$ ");
    //     if (input)
    //         printf("%s\n", input);
    //     else
    //         break ;
    //     add_history(input);
    //     free(input);
    // }
    system("leaks minishell");
    return(0);
}