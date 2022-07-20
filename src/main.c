#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    t_list  *env_list;
    t_env   *env_contents;
    char    *key;
    char    *value;
    int i;
    int j;
    int key_length = 0;
    int value_length = 0;

    i = 0;
    while (env[i])
    {
        // 초기화
        j = 0;
        env_list = (t_list *)malloc(sizeof(t_list));
        if (env_list == 0)
            return (0);

        env_list->content = (t_env *)malloc(sizeof(t_env));
        if (env_list->content == 0)
            return (0);
        // key & value 길이 구하는 코드
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
        // key & value 초기화
        key = (char *)malloc(key_length + 1);
        if (key == 0)
            return (0);
        value = (char *)malloc(value_length + 1);
        if (key == 0)
            return (0);
        // 구한 길이로 key & value 만드는 곳
        int x = 0;
        int y = 0;
        while (x < key_length)
        {
            key[x] = env[i][x];
            x++;
        }
        key[x] = '\0';
        x++;
        while (y < value_length)
        {
            value[y] = env[i][x];
            x++;
            y++;
        }
        value[y] = '\0';
        printf("%s\n", env[i]);
        printf("lens key: %d, value: %d\n", key_length, value_length);
        printf("data key: %s, value: %s\n", key, value);
        printf("\n-------------------------------------\n");
        key_length = 0;
        value_length = 0;
        free (env_list->content);
        free (env_list);
        free (key);
        free (value);
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