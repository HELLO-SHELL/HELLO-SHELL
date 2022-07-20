#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    t_list  *head;
    t_list  *env_list;
    t_env   *env_node;
    t_list  *curr;
    int     i;
    int     j;
    int     key_length = 0;
    int     value_length = 0;

    i = 0;
    head = (t_list *)malloc(sizeof(t_list));
    if (head == 0)
        return (0);
    // curr = head;
    while (env[i])//111111111111111
    {
        j = 0;
        env_node = (t_env *)malloc(sizeof(t_env));//111111111
        if (env_node == 0)
            return (0);
        // key & value 길이 구하는 코드
        // while (env[i][j] != '=')
        // {
        //     key_length++;
        //     j++;
        // }
        // j++;
        // while (env[i][j] != '\0')
        // {
        //     value_length++;
        
        //     j++;
        // }
        // key & value 스플릿 & env 구조체에 넣기

        char *delimiter = ft_strchr(env[i], '='); //key=value; // key, value
        // if (ft_strchr("\'\'", *s))
        //     s = ft_strchr(s + 1, *s);
        delimiter = '\0';
        char *key = env[i];
        char *value = delimiter + 1;
        env_node->key = ft_strdup(key);//111111111
        env_node->value = ft_strdup(value);//11111111


        env_node->key = ft_substr(env[i], 0, ft_strchr(env[i], '=') - env[i]);
        env_node->value = ft_substr(ft_strchr(env[i], '=') + 1, 0, ft_strlen(ft_strchr(env[i], '=')));

        // env_node->key = (char *)malloc(key_length + 1);
        // if (env_node->key == 0)
        //     return (0);
        // env_node->value = (char *)malloc(value_length + 1);
        // if (env_node->value == 0)
        //     return (0);
        // int x = 0;
        // int y = 0;
        // while (x < key_length)
        // {
        //     env_node->key[x] = env[i][x];
        //     x++;
        // }
        // env_node->key[x] = '\0';
        // x++;
        // while (y < value_length)
        // {
        //     env_node->value[y] = env[i][x];
        //     x++;
        //     y++;
        // }
        // env_node->value[y] = '\0';
        // key_length = 0;
        // value_length = 0;
        // i++;


        // t_list 구조체의 content에 t_env 넣으면서 연결리스트 구현하기
        env_list = ft_lstnew((void *)env_node);
        ft_lstadd_back(&head, env_list);
        // free (env_node->key);
        // free (env_node->value);
        // free (env_node);
        // free (env_list->content);
    }
    // while (curr->next)
    // {
    //     printf("key : %s, value : %s\n", curr->content->);
    //     curr = curr->next;
    // }
    
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
