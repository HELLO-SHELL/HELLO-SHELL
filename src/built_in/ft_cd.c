#include "../../include/minishell.h"

void  ft_cd(t_node *minishell)
{
    t_list *env_list;
    t_token *token_list;
    char *path;
    char *root;
    
    root = "/";
    path = NULL;
    env_list = minishell->env_list;
    token_list = minishell->token_list->next;
    // go_to_home_directory
    if (token_list == NULL || token_list->value[0] == '~'
        || (token_list->value[0] == '~' && token_list->value[1] == '/'))
        path = get_env_by_key(env_list, "HOME")->value;
    else if (token_list->value[0] == '/')
        path = root;
    else
        path = token_list->value;
    // 예외 조건에 대한 에러 출력 필요
    // OLDPWD 수정
    if (chdir(path) != 0)
            print_error_message("fail CD _ 수정 필요");
    // PWD 수정
    t_env *change_pwd;

    change_pwd = get_env_by_key(env_list, "PWD");
    free(change_pwd->value);
    change_pwd->value = NULL;
    change_pwd->value = getcwd(NULL, 0);
}