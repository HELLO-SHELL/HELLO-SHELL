#include "../../include/minishell.h"

// void	safe_free(void **p)
// {
// 	if (*p)
// 	{
// 		free(*p);
// 		*p = NULL;
// 	}
// 	return ;
// }

void    ft_unset(t_node *minishell)
{
    t_list  *env_list;
    t_list  *env_prev;
    t_list  *temp;
    t_list  *curr;
    t_token *token;

    token = minishell->token_list;
    env_list = minishell->env_list;
    // 유효하지 않은 것 error, 유효하지만 없는 것 return
    if (token->next == NULL)
        return ;
    token = token->next;
    while (token)
    {
        curr = env_list;
        while (curr)
        {
            temp = curr;
            if (is_same_string(((t_env *)temp->content)->key, token->value))
            {
                if (token->value == ((t_env *)temp->content)->key)
                    env_list = temp->next;
                else
                    env_prev->next = temp->next;
                free (((t_env *)temp->content)->key);
                ((t_env *)temp->content)->key = NULL;
                free (((t_env *)temp->content)->value);
                ((t_env *)temp->content)->value = NULL;
                free((temp->content));
                temp->content = NULL;
            }
            else
                env_prev = temp;
            curr = curr->next;
        }
        token = token->next;
    }
    return ;
}
