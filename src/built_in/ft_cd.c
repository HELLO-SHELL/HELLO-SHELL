#include "../../include/minishell.h"

int go_to_home_directory(t_list *env_list, t_token *token_list, char **path)
{
    if (token_list == NULL
        || (token_list->value[0] == '~' && token_list->value[1] == '\0')
        || (token_list->value[0] == '~' && token_list->value[1] == '/'
            && token_list->value[2] == '\0'))
    {
        *path = get_env_by_key(env_list, "HOME")->value;
        return (1);
    }
    return (0);
}

int go_to_path_directory_via_home(t_list *env_list, t_token *token_list, char **path)
{
    if (token_list->value[0] == '~' && token_list->value[1] == '/')
    {
        *path = get_env_by_key(env_list, "HOME")->value;
        if (chdir(*path) != 0)
            print_error_message("bash: cd: No such file or directory");
        *path = NULL;
        *path = ft_strchr(token_list->value, '/') + 1;
        return (1);
    }
    return (0);
}

void    go_to_path_directory(t_token *token_list, char **path)
{
    *path = token_list->value;
}

void    update_env_pwd(t_list **env_list, t_env **change_pwd)
{
    *change_pwd = get_env_by_key(*env_list, "PWD");
    free((*change_pwd)->value);
    (*change_pwd)->value = NULL;
    (*change_pwd)->value = getcwd(NULL, 0);
}

void  ft_cd(t_node *minishell)
{
    t_list *env_list;
    t_token *token_list;
    t_env *change_pwd;
    char *path;

    path = NULL;
    change_pwd = NULL;
    env_list = minishell->env_list;
    token_list = minishell->token_list->next;
    if (go_to_home_directory(env_list, token_list, &path))
        ;
    else if (go_to_path_directory_via_home(env_list, token_list, &path))
        ;
    else
        go_to_path_directory(token_list, &path);
    if (chdir(path) != 0)
        print_error_message("bash: cd: No such file or directory");
    update_env_pwd(&env_list, &change_pwd);
}
