#include "../../include/minishell.h"

int	ft_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (!buf)
	{
		free(buf);
		return (FAILURE);
	}
	printf("%s\n", buf);
	free(buf);
	return (SUCCESS);
}
