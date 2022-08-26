#include "../../include/minishell.h"

void	cut_token_by_pipe(t_token **tk_list)
{
	t_token	*curr;

	curr = *tk_list;
	while (*(curr->next->value) != '|')
		curr = curr->next;
	curr->next->prev = NULL;
	curr->next = NULL;
}

void	tk_listdelone(t_token **tk_list)
{
	if ((*tk_list)->prev)
		(*tk_list)->prev->next = (*tk_list)->next;
	if ((*tk_list)->next)
		(*tk_list)->next->prev = (*tk_list)->prev;
	(*tk_list)->prev = NULL;
	(*tk_list)->next = NULL;
	free((*tk_list)->value);
	(*tk_list)->value = NULL;
	free(*tk_list);
	(*tk_list) = NULL;
}

static int	is_special_token(int type)
{
	if (type == TK_FILE || type == TK_WORD || type == TK_DELIM)
		return (TRUE);
	return (FALSE);
}

int	check_token_error(t_token *token)
{
	t_token	*token_curr;
	int		count;

	count = all_token_count(token);
	token_curr = token;
	while (token_curr)
	{
		if (token->prev == NULL && is_same_string(token_curr->value, "|"))
			print_error_with_new_prompt("pipe can not be located in the first location.");
		else if (token->next == NULL && is_same_string(token_curr->value, "|"))
			print_error_with_new_prompt("pipe can not be located in the last location.");
		if (is_special_token(token_curr->type))
		{
			if (token->prev && is_special_token(token->prev->type))
				print_error_with_new_prompt("special token can't stuck each other");
			if (token->next && is_special_token(token->next->type))
				print_error_with_new_prompt("special token can't stuck each other");
		}
		token_curr = token_curr->next;
	}
}