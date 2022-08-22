#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "constant.h"
# include "get_next_line.h"
# include "color.h"

typedef struct s_token
{
	int				type;
	char			*value;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

typedef struct s_process
{
	int					argc;
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

typedef struct s_minishell
{
	t_list		*env_list;
	t_process	*ps_list;
	t_pipes		pipes;
	int			last_status;
}	t_minishell;

extern t_minishell g_minishell;

void	print_wallpaper(void);
void	init_minishell(void);

char	**command_split(char *str);
int		is_white_space(char c);
int		count_split_size(char *str);
int		split_line(t_split *split, char *line);
void	print_wallpaper(void);
t_token	*make_token_list(char **token_arr);
int		check_size(char *line, char **str, int *i);

/* built-in */
int		ft_pwd(void);
void	ft_env(t_list *env);
void	ft_cd(void);
void	ft_unset(void);
void	ft_export(void);
void	ft_exit(int status, char *err_msg);
void	ft_echo(char **argv);

/* utils */
/*		chore_utils		*/
int		is_same_string(char *str1, char *str2);
void	*ft_memccpy_under(void *dest, const void *src, int c, size_t n);
void	*safe_malloc(size_t size);

/*		env_utils		*/
void	split_env(t_env *env_node, char **env, int i);
void	env_linked_list(char **env);
t_env *get_env_by_key(t_list *env_list, char *key);
char	*get_env_value_by_key(t_list *env_list, char *key);
int		env_key_valid_checker(char *str);
t_token	*get_token_head(t_token *token);

/*		free_utils		*/
void	safe_free(void *p);
void    free_all(char *replaced_input, char **splitted_input);

/*		other			*/
int		handle_quote(t_split *split, char *line);
void	print_error_message(char *str);
void	ft_error_exit(char *str);
void	get_new_prompt();
void	heredoc_new_prompt();
char	*replace_whole_input_dollar(char *input);

/* parser */
void	set_process_list(t_process **ps_list, t_token *tk_lst);
int		count_pipe(t_token *tk_list);
void	init_pslist(t_process **lst, int cnt);
void	pslist_new(t_process **lst);
void	pslist_addback(t_process **lst);
void	init_process_struct(t_process **cmd_list);
void	cut_tail_by_pipe(t_token **tk_list);
void	tk_listdelone(t_token **tk_list);


/* executor */
/* 		executor.c	*/
void	executor(void);
void	execute_pipeline(void);
void	execute_single_cmdline(void);
void	execute_process(t_process *process, t_pipes *pipes);
int		execute_command(t_process *process);
void	execute_built_in(t_process *process);
int		is_built_in(t_process *ps_info);
/* 		heredoc.c 	*/
void	heredoc_to_temp_files(void);
void	change_heredoc_to_redirect(t_token *cmd_curr ,int idx);
void	make_temp_file(int file_index, char *delim);
/* 		is_func.c 	*/
int		is_accessable_command(t_token *cmd_list, char **paths);
char	*get_accessable_command(t_token *cmd_list, char **paths);
/* 		pipe.c	 	*/
void	init_pipe(t_pipes *p);
void	swap_pipe(t_pipes *p);
/* 		redirect.c 	*/
void	apply_redirection(char *filename, int mode);
void	apply_redirections(t_token *cmd_line);

/* 		safe_func.c	*/
void	safe_dup2(int fd, int to_fd);
int		safe_openfile(char *filename, int mode);
void	safe_close_pipes(t_pipes *p);
void	safe_close_pipe(int *fd);

/*		wait.c		*/
int		wait_childs(void);
pid_t	_get_last_pid(void);
int		wait_child(pid_t pid);
int		_signal_print(int status);
int		_trans_status(int status);

#endif
