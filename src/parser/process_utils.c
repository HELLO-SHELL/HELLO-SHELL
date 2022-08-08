#include "../../include/minishell.h"

void init_process_struct(t_process **cmd_list)
{
	t_process *temp;

	temp = safe_malloc(sizeof(t_process *));
	temp->head = NULL;
	temp->argc = 0;
	temp->argv = NULL;
	(*cmd_list) = temp;
}

void cut_tail_by_pipe(t_token **tk_list)
{
	t_token	*curr;

	curr = *tk_list;
	while (*(curr->next->value) != '|')
		curr = curr->next;
	curr->next->prev = NULL;
	curr->next = NULL;
}

void tk_listdelone(t_token **tk_list)
{
	if ((*tk_list)->prev)
		(*tk_list)->prev->next = (*tk_list)->next;
	if ((*tk_list)->next)
		(*tk_list)->next->prev = (*tk_list)->prev;
	(*tk_list)->prev = NULL;
	(*tk_list)->next = NULL;
	free(*tk_list);
	(*tk_list) = NULL;
}