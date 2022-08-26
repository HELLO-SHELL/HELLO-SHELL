#include "../../include/minishell.h"

static void	word_token_to_argv(t_process *ps_list)
{
	int		count;
	char	**new_argv;
	t_token	*token_curr;
	int		idx;

	idx = 0;
	count = word_type_count(ps_list->cmd_line);
	new_argv = safe_malloc(sizeof(char *) * (count + 1));
	token_curr = ps_list->cmd_line;
	while (token_curr)
	{
		if (token_curr->type == TK_WORD)
			new_argv[idx++] = ft_strdup(token_curr->value);
		token_curr = token_curr->next;
	}
	ps_list->argv = new_argv;
}

static void	insert_process_argv(t_process **ps_list)
{
	t_process	*lst_curr;

	lst_curr = *ps_list;
	while (lst_curr && lst_curr->cmd_line)
	{
		word_token_to_argv(lst_curr);
		lst_curr = lst_curr->next;
	}
}

static void	insert_process_head(t_process **ps_list, t_token *tk_list)
{
	t_process	*pslist_curr;
	t_token		*token_head;
	t_token		*token_curr;
	t_token		*for_delete;

	pslist_curr = *ps_list;
	token_curr = tk_list;
	while (pslist_curr)
	{
		pslist_curr->cmd_line = token_curr;
		while (token_curr && *(token_curr->value) != '|')
			token_curr = token_curr->next;
		if (token_curr && *(token_curr->value) == '|')
		{
			cut_token_by_pipe(&(pslist_curr->cmd_line));
			for_delete = token_curr;
			token_curr = token_curr->next;
			tk_listdelone(&for_delete);
		}
		insert_process_argv(&pslist_curr);
		pslist_curr = pslist_curr->next;
	}
}

void	set_process_list(t_process	**ps_list, t_token *tk_list)
{
	int			pipe_cnt;

	pipe_cnt = count_pipe(tk_list);
	init_pslist(ps_list, pipe_cnt);
	(*ps_list)->size = pipe_cnt + 1;
	insert_process_head(ps_list, tk_list);
}
