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
	if (type == TK_RDINPUT || type == TK_RDOUTPUT 
		|| type == TK_HEREDOC || type == TK_APPEND || type == TK_PIPE)
		return (TRUE);
	return (FALSE);
}

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