#include "../../../include/minishell.h"

void	safe_free(void *p)
{
	if (p)
	{
		free(p);
		p = NULL;
	}
	return ;
}