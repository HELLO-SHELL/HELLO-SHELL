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

int	word_type_count(t_token *token)
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

// static int	all_token_type_count(t_token *token)
// {
// 	t_token	*token_curr;
// 	int		count;

// 	count = 0;
// 	token_curr = token;
// 	while (token_curr)
// 	{
// 		count++;
// 		token_curr = token_curr->next;
// 	}
// 	return (count);
// }

// int	check_token_error(t_token *token)
// {
// 	t_token	*token_curr;
// 	int		count;
// 	int		idx;

// 	idx = 0;
// 	count = all_token_type_count(token);
// 	token_curr = token;
// 	while (token_curr)
// 	{
// 		if (idx == 0 && is_same_string(token->value, "|"))
// 		{
// 			print_error_message("pipe can not be located in the first location.");
// 			// free_all()
// 		}
// 		idx++;
// 		token_curr = token_curr->next;
// 	}
// }