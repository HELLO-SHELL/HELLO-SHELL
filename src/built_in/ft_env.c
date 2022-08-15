#include "../../include/minishell.h"

void	ft_env(t_list *env)
{
	while (env)
	{
		if (((t_env *)(env->content))->value != NULL)
			printf("%s=%s\n", ((t_env *)(env->content))->key, ((t_env *)(env->content))->value);
		env = env->next;
	}
}
