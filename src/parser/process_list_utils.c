#include "../../include/minishell.h"

int count_pipe(t_token *tk_list)
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
	}
	return (cnt);
}

void init_pslist(t_pslist **lst, int cnt)
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

void pslist_new(t_pslist **lst)
{
	t_pslist	*list_temp;
	t_process	*ps_temp;

	list_temp = safe_malloc(sizeof(t_pslist *));
	init_process_struct(&ps_temp);
	list_temp->value = ps_temp;
	list_temp->next = NULL;
	list_temp->prev = NULL;
	(*lst) = list_temp;
}

void pslist_addback(t_pslist **lst)
{
	t_pslist	*list_temp;
	t_pslist	*lst_idx;
	t_process	*ps_temp;

	lst_idx = *lst;
	list_temp = safe_malloc(sizeof(t_pslist *));
	init_process_struct(&ps_temp);
	while (lst_idx->next)
	{
		lst_idx = lst_idx->next;
	}
	list_temp->value = ps_temp;
	list_temp->next = NULL;
	list_temp->prev = lst_idx;
	lst_idx->next = list_temp;
}