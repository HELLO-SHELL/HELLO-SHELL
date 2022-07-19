#include "../../include/minishell.h"

int	print_env(t_list *env)
{
	while (env && env->next != NULL)
	{
		printf("%s\n", (char *)env->content);
		env = env->next;
	}
	if (env)
		printf("%s\n", (char *)env->content);
	return (SUCCESS);
}
