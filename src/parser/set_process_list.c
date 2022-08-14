#include "../../include/minishell.h"

static void word_token_to_char_list(t_process *ps_list)
{
	int		count;
	char	**new_argv;
	t_token	*token_curr;
	int		idx;

	idx = 0;
	count = word_type_count(ps_list->cmd_line);
	new_argv = (char **)malloc(sizeof(char *) * (count + 1));
	token_curr = ps_list->cmd_line;
	while(token_curr)
	{
		if (token_curr->type == TK_WORD)
			new_argv[idx] = ft_strdup(token_curr->value);
		idx++;
		token_curr = token_curr->next;
	}
}

static void insert_process_argv(t_process **ps_list)
{
	t_process	*lst_curr;

	lst_curr = *ps_list;
	while (lst_curr)
	{
		word_token_to_char_list(lst_curr);
		lst_curr = lst_curr->next;
	}
}

static void insert_process_head(t_process **ps_list, t_token *tk_list)
{
	t_process	*pslist_curr;
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
			pslist_curr->cmd_line = token_head;
			cut_token_by_pipe(&(pslist_curr->cmd_line));
			insert_process_argv(ps_list);
			for_delete = token_curr;
			token_curr = token_curr->next;
			tk_listdelone(&for_delete);
		}
		else
			pslist_curr->cmd_line = token_head;
		pslist_curr = pslist_curr->next;
	}
}

void set_process_list(t_process	**ps_list, t_token *tk_list)
{
	int			pipe_cnt;

	pipe_cnt = count_pipe(tk_list);
	init_pslist(ps_list, pipe_cnt);
	insert_process_head(ps_list, tk_list);
}
