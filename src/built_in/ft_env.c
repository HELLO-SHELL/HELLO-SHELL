#include "../../include/minishell.h"

void	ft_env(t_list *env)
{
	// = 있는지 없는지 확인하기
	while (env && env->next != NULL)
	{
		printf("%s = %s\n", ((t_env *)(env->content))->key, ((t_env *)(env->content))->value);
		env = env->next;
	}
	if (env)
		printf("%s = %s\n", ((t_env *)(env->content))->key, ((t_env *)(env->content))->value);
}
