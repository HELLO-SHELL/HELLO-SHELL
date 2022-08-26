#include "../../include/minishell.h"

static void    update_env_pwd(void)
{
    t_env *change_pwd;

    change_pwd = get_env_by_key("PWD");
    free((change_pwd)->value);
    (change_pwd)->value = NULL;
    (change_pwd)->value = getcwd(NULL, 0);
}

static void    set_path(char **path)
{
    t_list *env_list;
    t_token *cmd_list;

    env_list = g_minishell_info.env_list;
    cmd_list = g_minishell_info.ps_list->cmd_line->next;
    if (is_path_only_home(cmd_list))
        set_path_to_home(env_list, cmd_list, path);
    else if (is_path_pass_home(cmd_list))
        set_path_at_home(env_list, cmd_list, path);
    else
        set_path_to_input(cmd_list, path);
}

static void change_directory(char **path)
{
    if (chdir(*path) != 0)
        print_error_message("hello-shell: cd: No such file or directory");
}

void  ft_cd(void)
{
    char *path;

    path = NULL;
    set_path(&path);
    change_directory(&path);
    update_env_pwd();
}
