#include "../../include/minishell.h"

static char	*check_near_token(t_token *token)
{
	char	*err_msg;

	if (token->prev && is_special_token(token->prev->type))
		err_msg = "special token can't stuck each other";
	else if (token->next && is_special_token(token->next->type))
		err_msg = "special token can't stuck each other";
	else if (token->prev == NULL && token->next == NULL)
		err_msg = "special token can't exist alone";
	return ("");
}

int	check_token_error(t_token *token)
{
	t_token	*token_curr;
	char	*err_msg;

	token_curr = token;
	while (token_curr)
	{
		if (token_curr->prev == NULL && is_same_string(token_curr->value, "|"))
			err_msg = "pipe can not be located in the first location.";
		else if (token_curr->next == NULL
			&& is_same_string(token_curr->value, "|"))
			err_msg = "pipe can not be located in the last location.";
		else if (is_special_token(token_curr->type))
			err_msg = check_near_token(token_curr);
		if (!is_same_string("", err_msg))
		{
			print_error_message(err_msg);
			free_token_list(token);
			return (TRUE);
		}
		token_curr = token_curr->next;
	}
	return (FALSE);
}
