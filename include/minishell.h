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
	char			*value;
	struct s_env	*next;
}	t_env;

#endif
