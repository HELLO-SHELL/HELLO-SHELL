#include "../../include/minishell.h"

int	count_pipe(t_token *tk_list)
{
	t_token	*curr;
	int		cnt;

	curr = tk_list;
	cnt = 0;
	while (curr)
	{
		if (*(curr->value) == '|')
			cnt++;
		curr = curr->next;
		if (curr == NULL)
			return (cnt);
	}
	return (cnt);
}

void	cut_token_by_pipe(t_token **tk_list)
{
	t_token	*curr;

	curr = *tk_list;
	while (*(curr->next->value) != '|')
		curr = curr->next;
	curr->next->prev = NULL;
	curr->next = NULL;
}

int	is_special_token(int type)
{
	if (type == TK_RDINPUT || type == TK_RDOUTPUT
		|| type == TK_HEREDOC || type == TK_APPEND || type == TK_PIPE)
		return (TRUE);
	return (FALSE);
}
