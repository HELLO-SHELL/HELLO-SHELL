#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "constant.h"
# include "get_next_line.h"
# include "color.h"

typedef struct s_env {
	char	*key;
	char	*value;
}	t_env;

typedef struct s_node {
	t_list	*env_list;
}	t_node;

void	print_wallpaper(void);
void    init_minishell(t_node *minishell);

char	**command_split(char *str);
int		check_white_space(char c);
int		count_split_size(char *str);
int		check_size(char *line, char **str, int *i);

/* built-in */
int		ft_exit(int status);
int		ft_env(t_list *env);

/* utils */
int		is_same_string(char *str1, char *str2);
void    split_env(t_env *env_node, char **env, int i);
void    env_linked_list(t_node *minishell, char **env);

#endif
