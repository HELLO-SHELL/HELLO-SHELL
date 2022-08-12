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

// void    lst_delete_one(t_list *env_list, t_env *unsetting)
// {
//     t_list  *curr;

//     curr = env_list;
//     while (curr)
//     {
// 		if (((t_env *)curr->content) == unsetting)
//         {
//             if (curr == env_list)
//                 env_list = curr->next;
//             else
//                 unsetting = curr->next;

//             free (unsetting->key);
//             unsetting->key = NULL;
//             free (unsetting->value);
//             unsetting->value = NULL;
//             return ;
//         }
//         curr = curr->next;
//     }
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
    curr = env_list;
    if (token->next == NULL) // 유효하지 않은 것 error, 유효하지만 없는 것 return
        return ;
    token = token->next;
    while (token)
    {
        while (curr)
        {
            temp = curr;
            if (is_same_string(((t_env *)temp->content)->key, token->value))
            {
                // 첫번째 노드일 때
                if (token->value == ((t_env *)temp->content)->key)
                    env_list = temp->next;
                else // 첫번째 노드가 아닐 때
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
