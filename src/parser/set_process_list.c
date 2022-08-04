#include "../../include/minishell.h"

// static int is_command(char *str)
// {
// 	if (is_same_string(str, "echo") || is_same_string(str, "cd")
// 		|| is_same_string(str, "exit") || is_same_string(str, "export") 
// 			|| is_same_string(str, "unset") || is_same_string(str, "env") 
// 				|| is_same_string(str, "pwd"))
// 		return (TRUE);
// 	return (FALSE);
// }

static void init_process_struct(t_process **cmd_list)
{
	t_process *temp;

	temp = malloc(sizeof(t_process *));
	if (!temp)
		exit(FAILURE);
	temp->head = NULL;
	temp->command = NULL;
	temp->prefix = NULL;
	temp->suffix = NULL;
	(*cmd_list) = temp;
}

static int count_pipe(t_token *tk_list)
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

static void pslist_new(t_pslist **lst)
{
	t_pslist	*list_temp;
	t_process	*ps_temp;

	list_temp = malloc(sizeof(t_pslist *));
	init_process_struct(&ps_temp);
	if (!list_temp || !ps_temp)
		exit(EXIT_FAILURE);
	list_temp->value = ps_temp;
	list_temp->next = NULL;
	list_temp->prev = NULL;
	(*lst) = list_temp;
}

static void pslist_addback(t_pslist **lst)
{
	t_pslist	*list_temp;
	t_pslist	*lst_idx;
	t_process	*ps_temp;

	lst_idx = *lst;
	list_temp = malloc(sizeof(t_pslist *));
	init_process_struct(&ps_temp);
	if (!list_temp || !ps_temp)
		exit(EXIT_FAILURE);
	while (lst_idx->next)
	{
		lst_idx = lst_idx->next;
	}
	list_temp->value = ps_temp;
	list_temp->next = NULL;
	list_temp->prev = lst_idx;
	lst_idx->next = list_temp;
}

static void init_pslist(t_pslist **lst, int cnt)
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

static void cut_tail(t_token **tk_list)
{
	t_token	*curr;

	curr = *tk_list;
	while (*(curr->next->value) != '|')
		curr = curr->next;
	curr->next->prev = NULL;
	curr->next = NULL;
}

static void tk_listdelone(t_token **tk_list)
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
			cut_tail(&(pslist_curr->value->head));
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
	printf("pipe count: %d\n", pipe_cnt);
	init_pslist(ps_list, pipe_cnt);
	insert_command_head(ps_list, tk_list);
	// deleted_token tester for cmdlist
	command_list_tester(*ps_list);
}