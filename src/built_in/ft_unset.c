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

void    lst_delete_one(t_list *env_list, t_env *temp)
{
    t_list  *curr;

    curr = env_list;
    while (curr)
    {
		if (((t_env *)curr->content) == temp)
        {
            if (curr == env_list)
                env_list = curr->next;
            else
                
            free (temp->key);
            temp->key = NULL;
            free (temp->value);
            temp->value = NULL;
            return ;
        }
        curr = curr->next;
    }
    
}

void    ft_unset(t_node *minishell)
{
    t_list  *env_list;
    t_env   *temp;
    t_token *token;

    env_list = minishell->env_list;
    token = minishell->token_list;
    if (token->next == NULL)
        return ;
    token = token->next;
    while (token)
    {
        temp = get_env_by_key(env_list, token->value);
        if (temp)
            lst_delete_one(env_list, temp);
        else
            return ;
        token = token->next;
    }
}
