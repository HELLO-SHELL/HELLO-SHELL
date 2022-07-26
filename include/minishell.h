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

enum e_token_type
{
	TK_EOF,
	TK_RDINPUT,
	TK_RDOUTPUT,
	TK_APPEND,
	TK_PIPE,
	TK_COMMAND,
	TK_FILE,
	TK_HEREDOC,
	TK_DELIM,
	TK_WORD
};

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

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
int		split_line(char *line, char **str, int *i);
void	print_wallpaper(void);
t_token	*set_token_list(char **token_arr);
int		check_size(char *line, char **str, int *i);

/* built-in */
int		ft_exit(int status);
int		ft_env(t_list *env);

/* utils */
int		is_same_string(char *str1, char *str2);
void    split_env(t_env *env_node, char **env, int i);
void    env_linked_list(t_node *minishell, char **env);
t_token	*get_token_head(t_token *token);

#endif
