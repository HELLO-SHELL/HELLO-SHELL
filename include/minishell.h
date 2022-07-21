#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

char	**command_split(char *str);
int		check_white_space(char c);
int		count_split_size(char *str);
int		check_size(char *line, char **str, int *i);
void	print_wallpaper(void);

#endif
