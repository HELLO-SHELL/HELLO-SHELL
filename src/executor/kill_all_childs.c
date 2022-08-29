#include "../../include/minishell.h"

void	kill_all_childs(int input)
{

	t_process	*ps_curr;

	printf("I'M HERE!!!\n");
	(void) input;
	ps_curr = g_minishell_info.ps_list;
	printf("ps_curr: %p\n", ps_curr);
	while (ps_curr)
	{
		printf("pid: %d\n", ps_curr->pid);
		kill(ps_curr->pid, SIGINT);
		ps_curr = ps_curr->next;
	}
}

void	kill_all_child(int input)
{

	t_process	*ps_curr;

	(void) input;
	ps_curr = g_minishell_info.ps_list;
	kill(ps_curr->pid, SIGINT);
}
