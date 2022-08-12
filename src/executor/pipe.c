#include "../../include/minishell.h"

static void	_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	swap_pipe(t_pipes *p)
{
	_swap(&(p->prev_pipe[READ]), &(p->next_pipe[READ]));
	_swap(&(p->prev_pipe[WRITE]), &(p->next_pipe[WRITE]));
}

void	init_pipe(t_pipes *p)
{
	p->prev_pipe[READ] = -1;
	p->prev_pipe[WRITE] = -1;
	p->next_pipe[READ] = -1;
	p->next_pipe[WRITE] = -1;
}

void	close_pipe(int *fd)
{
	if (*fd != -1)
	{
		if (close(*fd))
			print_error_message("fail close()\n");
		*fd = -1;
	}
}

void	close_pipes(t_pipes *p)
{
	close_pipe(&p->prev_pipe[READ]);
	close_pipe(&p->prev_pipe[WRITE]);
	close_pipe(&p->next_pipe[READ]);
	close_pipe(&p->next_pipe[WRITE]);
}
