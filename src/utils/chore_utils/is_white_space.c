#include "../../../include/minishell.h"

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}
