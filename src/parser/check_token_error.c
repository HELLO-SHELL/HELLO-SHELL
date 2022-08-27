#include "../../include/minishell.h"

int	check_token_error(t_token *token)
{
	t_token	*token_curr;
	int		is_error;

	is_error = FALSE;
	token_curr = token;
	while (token_curr)
	{
		if (token_curr->prev == NULL && is_same_string(token_curr->value, "|"))
			is_error = print_error_with_new_prompt("pipe can not be located in the first location.");
		else if (token_curr->next == NULL && is_same_string(token_curr->value, "|"))
			is_error = print_error_with_new_prompt("pipe can not be located in the last location.");
		else if (is_special_token(token_curr->type))
		{
			if (token_curr->prev && is_special_token(token_curr->prev->type))
				is_error = print_error_with_new_prompt("special token can't stuck each other");
			if (token_curr->next && is_special_token(token_curr->next->type))
				is_error = print_error_with_new_prompt("special token can't stuck each other");
		}
		if (is_error)
			return (TRUE);
		token_curr = token_curr->next;
	}
	return (FALSE);
}