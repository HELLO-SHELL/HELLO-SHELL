#include "../../include/minishell.h"

int go_to_home_directory(t_list *env_list, t_token *token_list, char *path)
{
    if (token_list == NULL || token_list->value[0] == '~'
        || (token_list->value[0] == '~' && token_list->value[1] == '/'))
    {
        path = get_env_by_key(env_list, "HOME")->value;
        return (1);
    }
    return (0);
}

int go_to_root_directory(t_list *env_list, t_token *token_list, char *path)
{
    char *root;

    root = "/";
    if (token_list->value[0] == '/')
    {
        path = root;
        return (1);
    }
    return (0);
}

void    go_to_path_directory(t_token **token_list, char *path)
{
    path = (*token_list)->value;
}

void  ft_cd(t_node *minishell)
{
    t_list *env_list;
    t_token *token_list;
    char *path;

    path = NULL;
    env_list = minishell->env_list;
    token_list = minishell->token_list->next;
    // go_to_home_directory
    // go_to_root
    // go_to_path
    // update_env_pwd
    if (go_to_home_directory(env_list, token_list, path))
        ;
    else if (go_to_root_directory(env_list, token_list, path))
        ;
    else
        go_to_path_directory(&token_list, path);

    // 예외 조건에 대한 에러 출력 필요
    if (chdir(path) != 0)
            print_error_message("fail CD _ 수정 필요");
    // PWD 수정
    // undate_env_pwd();
    t_env *change_pwd;

    change_pwd = get_env_by_key(env_list, "PWD");
    free(change_pwd->value);
    change_pwd->value = NULL;
    change_pwd->value = getcwd(NULL, 0);
}

// OLDPWD 수정
