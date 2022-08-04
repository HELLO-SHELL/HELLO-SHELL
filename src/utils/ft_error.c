#include "../../include/minishell.h"

void    print_error_message(char *str)
{
	write(2, RED, ft_strlen(RED));
    ft_putendl_fd(str, STDERR_FILENO);
	write(2, COLOR_RESET, ft_strlen(COLOR_RESET));
}

void    ft_error_exit(char *str)
{
    print_error_message(str);
    exit(EXIT_FAILURE);
}
