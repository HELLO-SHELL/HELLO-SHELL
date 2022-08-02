#include "../../include/minishell.h"

int	ft_env(t_list *env)
{
	while (env && env->next != NULL)
	{
		printf("%s = %s\n", ((t_env *)(env->content))->key, ((t_env *)(env->content))->value);
		env = env->next;
	}
	if (env)
		printf("%s = %s\n", ((t_env *)(env->content))->key, ((t_env *)(env->content))->value);
	return (SUCCESS);
}