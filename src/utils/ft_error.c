#include "../../include/minishell.h"

void    ft_error(char *str)
{
    ft_putendl_fd(str, 2);
    exit(EXIT_FAILURE)   
}
