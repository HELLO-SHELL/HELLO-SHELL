#include "../../include/minishell.h"

int	token_word_count(t_token *token)
{
	t_token	*token_curr;
	int		count;

	count = 0;
	token_curr = token;
	while (token_curr)
	{
		if (token_curr->type == TK_WORD)
			count++;
		token_curr = token_curr->next;
	}
	return (count);
}
