#include "../include/minishell.h"

int main(int ac, char **av, char **env)
{
    t_list  *head;
    t_list  *env_list;
    t_env   *env_node;
    t_list  *curr;
    char *key;
    char *delimiter;
    char *value;
    int     i;

    i = 0;
    head = 0;
    while (env[i])
    {
        env_node = (t_env *)malloc(sizeof(t_env));
        if (env_node == 0)
            return (0);
        delimiter = ft_strchr(env[i], '=');
        *delimiter = 0;
        key = env[i];
        value = delimiter + 1;
        env_node->key = ft_strdup(key);
        env_node->value = ft_strdup(value);

        // t_list 구조체의 content에 t_env 넣으면서 연결리스트 구현하기
        env_list = ft_lstnew(env_node);
        ft_lstadd_back(&head, env_list);
        i++;
    }
    curr = head;
    while (curr->next)
    {
        printf("key = %s, value = %s\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
        curr = curr->next;
    }    
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
