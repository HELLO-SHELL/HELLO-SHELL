#include "../../../include/minishell.h"

int set_path_to_home(t_list *env_list, t_token *cmd_list, char **path)
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
            print_error_message("hello-shell: cd: No such file or directory");
        *path = NULL;
        *path = ft_strchr(cmd_list->value, '/') + 1;
        return (1);
    }
    return (0);
}

void    set_path_to_input(t_token *cmd_list, char **path)
{
    *path = cmd_list->value;
}
