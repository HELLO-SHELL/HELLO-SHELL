#include "../../include/minishell.h"

void	ft_env(void)
{
	t_list	*env;

	env = g_minishell_info.env_list;
	while (env)
	{
		if (((t_env *)(env->content))->value != NULL)
			printf("%s=%s\n", ((t_env *)(env->content))->key,
				((t_env *)(env->content))->value);
		env = env->next;
	}
}
