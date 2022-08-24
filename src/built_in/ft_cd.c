#include "../../include/minishell.h"

static int set_path_to_home(t_list *env_list, t_token *cmd_list, char **path)
{
    if (cmd_list == NULL
        || (cmd_list->value[0] == '~' && cmd_list->value[1] == '\0')
        || (cmd_list->value[0] == '~' && cmd_list->value[1] == '/'
            && cmd_list->value[2] == '\0'))
    {
        *path = get_env_value_by_key("HOME");
        return (1);
    }
    return (0);
}

int set_path_at_home(t_list *env_list, t_token *cmd_list, char **path)
{
    if (cmd_list->value[0] == '~' && cmd_list->value[1] == '/')
    {
        *path = get_env_value_by_key("HOME");
        if (chdir(*path) != 0)
            print_error_message("HELLO-SHELL: cd: No such file or directory");
        *path = NULL;
        *path = ft_strchr(cmd_list->value, '/') + 1;
        return (1);
    }
    return (0);
}

static void    set_path_to_input(t_token *cmd_list, char **path)
{
    *path = cmd_list->value;
}

static void    update_env_pwd(t_env **change_pwd)
{
    t_list *env_list;

    env_list = g_minishell_info.env_list;
    *change_pwd = get_env_by_key("PWD");
    free((*change_pwd)->value);
    (*change_pwd)->value = NULL;
    (*change_pwd)->value = getcwd(NULL, 0);
}

static void    set_path(char **path)
{
    t_list *env_list;
    t_token *cmd_list;

    env_list = g_minishell_info.env_list;
    cmd_list = g_minishell_info.ps_list->cmd_line->next;
    if (set_path_to_home(env_list, cmd_list, path))
        ;
    else if (set_path_at_home(env_list, cmd_list, path))
        ;
    else
        set_path_to_input(cmd_list, path);
}

static void change_directory(char **path)
{
    if (chdir(*path) != 0)
        print_error_message("bash: cd: No such file or directory");
}

void  ft_cd(void)
{
    t_env *change_pwd;
    char *path;

    path = NULL;
    change_pwd = NULL;
    set_path(&path);
    change_directory(&path);
    update_env_pwd(&change_pwd);
}
