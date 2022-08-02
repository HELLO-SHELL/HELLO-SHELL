#include "../../include/minishell.h"

t_token	*get_token_head(t_token *token)
{
	while (token)
	{
		if (token->prev == NULL)
			return (token);
		token = token->prev;
	}
	return (NULL);
}
