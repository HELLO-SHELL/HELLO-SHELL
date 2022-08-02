#include "../../include/minishell.h"

// 1) token list print tester
// kyungsle
void token_list_tester(t_token *token_list)
{
	while (token_list)
	{
		printf("%s$\n", token_list->value);
		token_list = token_list->next;
	}
}

// 2) cmd list print tester
// kyungsle
void command_list_tester(t_pslist *cmd_lst)
{
	while (cmd_lst)
	{
		printf("pslist pointer: %p$\n", cmd_lst);
		while (cmd_lst->value->head)
		{
			printf("head value: %s$\n", cmd_lst->value->head->value);
			cmd_lst->value->head = cmd_lst->value->head->next;
		}
		cmd_lst = cmd_lst->next;
	}
}