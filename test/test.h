# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../lib/libft/libft.h"

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_process
{
	char				**argv;
	char				**envp;
	char				**paths;
	int					size;
	pid_t				pid;
	t_token				*cmd_line;
	struct s_process	*next;
}	t_process;

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

typedef struct s_split
{
	int		split_size;
	char	**result;
	char	*str;
	int		flag;
	int		rtn;
	int		i;
	int		j;
}	t_split;

typedef struct	s_pipes
{
	int	prev_pipe[2];
	int	next_pipe[2];
}	t_pipes;

typedef struct s_node
{
	t_list		*env_list;
	t_process	ps_list;
	t_pipes		pipes;
}	t_minishell;