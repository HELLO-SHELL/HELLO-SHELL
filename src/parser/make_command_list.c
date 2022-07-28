#include "../../include/minishell.h"

int is_command(char *str)
{
    if (is_same_string(str, 'echo') || is_same_string(str, 'cd')
        || is_same_string(str, 'exit') || is_same_string(str, 'export') 
            || is_same_string(str, 'unset') || is_same_string(str, 'env') 
                || is_same_string(str, 'pwd'))
        return (TRUE);
    return (FALSE);
}

void init_command_list(t_command *cmd_list)
{
    cmd_list = malloc(sizeof(t_command *));
    if (!cmd_list)
        exit(FAILURE);
    cmd_list->command = NULL;
    cmd_list->prefix = NULL;
    cmd_list->suffix = NULL;
    cmd_list->prev = NULL;
    cmd_list->next = NULL;
}

void split_command(t_token *tk_list)
{
    t_token     *curr;
    t_token     *head;
    t_command   *cmd_list;

    init_command_list(cmd_list);
    curr = tk_list;
    head = tk_list;
    while (1)
    {
        if (!curr || curr->type == TK_PIPE)
        {
            if (is_command(head->value))
                cmd_list->command = head;
        }
        curr = curr->next;
    }
    
}