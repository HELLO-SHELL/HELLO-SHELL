#include "../../include/minishell.h"

typedef struct s_env{
	char			*value;
	struct s_env	next;
}	t_env;

int	ft_env(t_env *env)
{
	while (env && env->next != NULL)
	{
		ft_putendl_fd(env->value, 1);
		env = env->next;
	}
	if (env)
		ft_putendl_fd(env->value, 1);
	return (SUCCESS);
}
