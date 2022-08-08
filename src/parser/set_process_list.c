#include "../../include/minishell.h"

static void insert_command_head(t_pslist **ps_list, t_token *tk_list)
{
	t_pslist	*pslist_curr;
	t_token		*token_head;
	t_token		*token_curr;
	t_token		*for_delete;

	pslist_curr = *ps_list;
	token_curr = tk_list;
	while (pslist_curr)
	{
		token_head = token_curr;
		while (token_curr && *(token_curr->value) != '|')
			token_curr = token_curr->next;
		if (token_curr && *(token_curr->value) == '|')
		{
			pslist_curr->value->head = token_head;
			cut_tail_by_pipe(&(pslist_curr->value->head));
			for_delete = token_curr;
			token_curr = token_curr->next;
			tk_listdelone(&for_delete);
		}
		else
			pslist_curr->value->head = token_head;
		pslist_curr = pslist_curr->next;
	}
}


void set_command_list(t_pslist	**ps_list, t_token *tk_list)
{
	int			pipe_cnt;

	pipe_cnt = count_pipe(tk_list);
	init_pslist(ps_list, pipe_cnt);
	insert_command_head(ps_list, tk_list);
	command_list_tester(*ps_list);
}