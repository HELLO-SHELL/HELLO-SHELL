#include "../../include/minishell.h"

int is_command(char *str)
{
	if (is_same_string(str, 'echo') || is_same_string(str, 'cd')
		|| is_same_string(str, 'exit') || is_same_string(str, 'export') 
			|| is_same_string(str, 'unset') || is_same_string(str, 'env') 
				|| is_same_string(str, 'pwd'))
		return (TRUE);
	return (FALSE);
}

void init_command_list(t_command *cmd_list)
{
	cmd_list = malloc(sizeof(t_command *));
	if (!cmd_list)
		exit(FAILURE);
	cmd_list->head = NULL;
	cmd_list->command = NULL;
	cmd_list->prefix = NULL;
	cmd_list->suffix = NULL;
}

int count_pipe(t_token *tk_lst)
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

void cmdlst_new(t_cmdlst **lst)
{
	t_cmdlst	*lst_temp;
	t_command	*cmd_temp;

	lst_temp = malloc(sizeof(t_cmdlst));
	cmd_temp = malloc(sizeof(t_command));
	if (!lst_temp || !cmd_temp)
		exit(EXIT_FAILURE);
	lst_temp->value = cmd_temp;
	lst_temp->next = NULL;
	lst_temp->prev = NULL;
	(*lst) = lst_temp;
}

void cmdlst_addback(t_cmdlst **lst)
{
	t_cmdlst	*lst_temp;
	t_command	*cmd_temp;

	lst_temp = malloc(sizeof(t_cmdlst));
	cmd_temp = malloc(sizeof(t_command));
	if (!lst_temp || !cmd_temp)
		exit(EXIT_FAILURE);
	lst_temp->value = cmd_temp;
	lst_temp->next = NULL;
	lst_temp->prev = (*lst);
	(*lst)->next = lst_temp;
	(*lst) = (*lst)->next;
}

void init_cmdlst(t_cmdlst **lst, int cnt)
{
	int	i;

	i = 0;
	while (i < cnt)
	{
		if (i == 0)
			cmdlst_new(lst);
		else
			cmdlst_addback(lst);
		i++;
	}
}

void insert_token_to_command(t_cmdlst **cmd_lst, t_token *tk_lst)
{
	t_cmdlst	*cmdlst_curr;
	t_token		*cmd_head;
	t_token		*cmd_curr;

	cmdlst_curr = *cmd_lst;
	cmd_curr = tk_lst;
	while (cmdlst_curr)
	{
		cmd_head = cmd_curr;
		while (cmd_curr && *(cmd_curr->value) != '|')
			cmd_curr = cmd_curr->next;
		if (*(cmd_curr->value) == '|')
		{
			cmdlst_curr->value->head = cmd_head;
		}
		cmdlst_curr = cmdlst_curr->next;
	}
	
}

void split_command(t_token *tk_lst)
{
	t_cmdlst	*cmd_lst;
	int			pipe_cnt;

	pipe_cnt = count_pipe(tk_lst);
	init_cmdlst(&cmd_lst, pipe_cnt);
}