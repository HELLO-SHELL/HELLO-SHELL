#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "libft.h"
# include "constant.h"

typedef struct s_env {
	char	*key;
	char	*value;
}	t_env;

typedef struct s_node {
	t_list	*env_list;
}	t_node;

// int	print_env(t_list *env);
void    init_minishell(void);

void    split_env(t_env *env_node, char **env, int i);
void    env_linked_list(t_node *minishell, char **env);

#endif
