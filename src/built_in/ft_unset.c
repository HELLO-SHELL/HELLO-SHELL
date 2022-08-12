#include "../../include/minishell.h"

void	safe_free(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
	return ;
}

void    unsetting(t_list *env_list, t_token *token)
{
    t_list  *curr;
    t_list  *temp;
    t_list  *env_prev;

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
            safe_free (((t_env *)temp->content)->key);
            safe_free (((t_env *)temp->content)->value);
            safe_free((temp->content));
        }
        else
            env_prev = temp;
        curr = curr->next;
    }
}

int unset_have_no_parm(t_token *token)
{
    if (token->next == NULL)
    {
        token = token->next;
        return (1);
    }
    token = token->next;
    return (0);
}

void    ft_unset(t_node *minishell)
{
    t_list  *env_list;
    t_token *token;

    env_list = minishell->env_list;
    token = minishell->token_list;
    if (unset_have_no_parm(token))
        return ;
    token = token->next;
    while (token)
    {
        unsetting(env_list, token);
        token = token->next;
    }
    return ;
}
