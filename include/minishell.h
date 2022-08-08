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

# define TRUE 1
# define FALSE 0

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
	TK_WORD,
	TK_CMD
};

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_process
{
	char	*argv;
	int		argc;
	t_token	*head;
}	t_process;

typedef struct s_pslist
{
	t_process		*value;
	struct s_pslist	*prev;
	struct s_pslist	*next;
}	t_pslist;

typedef struct s_env {
	char	*key;
	char	*value;
}	t_env;

typedef struct s_node {
	t_list	*env_list;
	t_token	*token_list;
}	t_node;

void	print_wallpaper(void);
void	init_minishell(t_node *minishell);

char	**command_split(char *str);
int		check_white_space(char c);
int		count_split_size(char *str);
int		split_line(char *line, char **str, int *i, int *j);
void	print_wallpaper(void);
t_token	*set_token_list(char **token_arr);
int		check_size(char *line, char **str, int *i);

/* built-in */
void	ft_env(t_list *env);
void	ft_export(t_node *minishell);
int		ft_pwd(void);
void		ft_exit(int status, char *err_msg);

/* utils */
int		is_same_string(char *str1, char *str2);
void	split_env(t_env *env_node, char **env, int i);
void	env_linked_list(t_node *minishell, char **env);
t_token	*get_token_head(t_token *token);
void	*safe_malloc(size_t size);
void	print_error_message(char *str);
void	ft_error_exit(char *str);
void	get_new_prompt(int sig);

/* parser */
void	set_command_list(t_pslist **ps_list, t_token *tk_lst);
int		count_pipe(t_token *tk_list);
void	init_pslist(t_pslist **lst, int cnt);
void	pslist_new(t_pslist **lst);
void	pslist_addback(t_pslist **lst);
void	init_process_struct(t_process **cmd_list);
void	cut_tail_by_pipe(t_token **tk_list);
void	tk_listdelone(t_token **tk_list);

/* temp tester!
delete this before submit */
void token_list_tester(t_token *token_list);
void command_list_tester(t_pslist *ps_list);

#endif
