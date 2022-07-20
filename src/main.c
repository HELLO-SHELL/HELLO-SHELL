#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    t_list  *env_list;
    t_env   *env_contents;
    int i;
    int j;
    int key_length = 0;
    int value_length = 0;

    // while (env[i])
    // {
    //     printf("Before List : %s\n", env[i]);
    //     i++;
    // }
    // printf("---------------------------------");
    // key 와 value 는 길이를 측정하면서 malloc해야함
    // env[i] 를 = 을 기준으로 앞뒤를 나누고, env_contents 의 key와 value에 길이로 malloc하고 할당
    while (*env)
    {
        i = 0;
        j = 0;
        env_list = (t_list *)malloc(sizeof(t_list));
        if (env_list == 0)
            return (0);

        env_list->content = (t_env *)malloc(sizeof(t_env));
        if (env_list->content == 0)
            return (0);

        env_contents = (t_env *)malloc(sizeof(t_env));
        if (env_contents == 0)
            return (0);

        env_list->content = env_contents;
        
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
        env++;
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