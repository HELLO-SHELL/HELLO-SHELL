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

static void init_command(t_command **cmd_list)
{
	t_command *temp;

	temp = malloc(sizeof(t_command *));
	if (!temp)
		exit(FAILURE);
	temp->head = NULL;
	temp->command = NULL;
	temp->prefix = NULL;
	temp->suffix = NULL;
	(*cmd_list) = temp;
}

static int count_pipe(t_token *tk_lst)
{
	t_token	*curr;
	int		cnt;

	curr = tk_lst;
	cnt = 0;
	while (curr)
	{
		if (*(curr->value) == '|')
			cnt++;
		curr = curr->next;
	}
	return (cnt);
}

static void cmdlst_new(t_cmdlst **lst)
{
	t_cmdlst	*lst_temp;
	t_command	*cmd_temp;

	lst_temp = malloc(sizeof(t_cmdlst *));
	init_command(&cmd_temp);
	if (!lst_temp || !cmd_temp)
		exit(EXIT_FAILURE);
	lst_temp->value = cmd_temp;
	lst_temp->next = NULL;
	lst_temp->prev = NULL;
	(*lst) = lst_temp;
}

static void cmdlst_addback(t_cmdlst **lst)
{
	t_cmdlst	*lst_temp;
	t_command	*cmd_temp;

	lst_temp = malloc(sizeof(t_cmdlst *));
	init_command(&cmd_temp);
	if (!lst_temp || !cmd_temp)
		exit(EXIT_FAILURE);
	lst_temp->value = cmd_temp;
	lst_temp->next = NULL;
	lst_temp->prev = (*lst);
	(*lst)->next = lst_temp;
	(*lst) = (*lst)->next;
}

static void init_cmdlst(t_cmdlst **lst, int cnt)
{
	int	i;

	i = 0;
	while (i <= cnt)
	{
		if (i == 0)
			cmdlst_new(lst);
		else
			cmdlst_addback(lst);
		i++;
	}
}

static void cut_tail(t_token **tk_lst)
{
	t_token	*curr;

	curr = *tk_lst;
	while (*(curr->next->value) != '|')
		curr = curr->next;
	curr->next->prev = NULL;
	curr->next = NULL;
}

static void tk_lstdelone(t_token **tk_lst)
{
	if ((*tk_lst)->prev)
		(*tk_lst)->prev->next = (*tk_lst)->next;
	if ((*tk_lst)->next)
		(*tk_lst)->next->prev = (*tk_lst)->prev;
	(*tk_lst)->prev = NULL;
	(*tk_lst)->next = NULL;
	free(*tk_lst);
	(*tk_lst) = NULL;
}

static void insert_command_head(t_cmdlst **cmd_lst, t_token *tk_lst)
{
	t_cmdlst	*cmdlst_curr;
	t_token		*cmd_head;
	t_token		*cmd_curr;
	t_token		*temp;

	cmdlst_curr = *cmd_lst;
	cmd_curr = tk_lst;
	while (cmdlst_curr)
	{
		cmd_head = cmd_curr;
		while (cmd_curr && *(cmd_curr->value) != '|')
			cmd_curr = cmd_curr->next;
		if (cmd_curr && *(cmd_curr->value) == '|')
		{
			cmdlst_curr->value->head = cmd_head;
			cut_tail(&(cmdlst_curr->value->head));
			temp = cmd_curr;
			cmd_curr = cmd_curr->next;
			tk_lstdelone(&temp);
		}
		else
			cmdlst_curr->value->head = cmd_head;
		cmdlst_curr = cmdlst_curr->next;
	}
}

void set_command_list(t_cmdlst	**cmd_lst, t_token *tk_lst)
{
	int			pipe_cnt;

	pipe_cnt = count_pipe(tk_lst);
	// printf("pipe: %d\n", pipe_cnt);
	init_cmdlst(cmd_lst, pipe_cnt);
	insert_command_head(cmd_lst, tk_lst);
}