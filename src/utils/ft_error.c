#include "../../include/minishell.h"

void    ft_error(char *str)
{
    ft_putendl_fd(str, STDERR_FILENO);

    exit(EXIT_FAILURE)   
}
