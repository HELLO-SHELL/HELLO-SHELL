#include "../../include/minishell.h"

int ft_pwd(void)
{
	char	*buf;

	buf = getcwd(NULL, 0);
	if (!buf)
	{
		free(buf);
		return (0);
	}
	printf("%s", buf);
	free(buf);
	return (1);
}
