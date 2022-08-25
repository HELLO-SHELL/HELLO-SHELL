#include "../../include/minishell.h"

int count_pipe(t_token *tk_list)
{
	t_token	*curr;
	int		cnt;

	curr = tk_list;
	cnt = 0;
	if (*(curr->value) == '|')
		ft_error_exit("pipe can not be located in the first location.");
	while (curr)
	{
		if (*(curr->value) == '|')
			cnt++;
		curr = curr->next;
		if (curr == NULL)
			return (cnt);
		if (curr->next == NULL && *(curr->value) == '|')
			ft_error_exit("pipe can not be located in the last location.");
	}
	return (cnt);
}

void pslist_new(t_process **lst)
{
	t_process	*ps_temp;

	ps_temp = safe_malloc(sizeof(t_process));
	ps_temp->argv = NULL;
	ps_temp->cmd_line = NULL;
	ps_temp->next = NULL;
	(*lst) = ps_temp;
}

void pslist_addback(t_process **lst)
{
	t_process	*lst_idx;
	t_process	*ps_temp;

	lst_idx = *lst;
	ps_temp = safe_malloc(sizeof(t_process));
	while (lst_idx->next)
	{
		lst_idx = lst_idx->next;
	}
	ps_temp->argv = NULL;
	ps_temp->cmd_line = NULL;
	ps_temp->next = NULL;
	lst_idx->next = ps_temp;
}

void init_pslist(t_process **lst, int cnt)
{
	int	i;

	i = 0;
	while (i <= cnt)
	{
		if (i == 0)
			pslist_new(lst);
		else
			pslist_addback(lst);
		i++;
	}
}
