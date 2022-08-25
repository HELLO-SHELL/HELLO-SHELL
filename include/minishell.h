#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include <sys/wait.h>
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
	int			ft_stdin;
	int			ft_stdout;
	int			ft_stderr;
	char		*last_status;
}	t_minishell;

extern t_minishell g_minishell_info;

void	print_wallpaper(void);
void	init_minishell(void);
void 	init_minishell_info(void);

char	**command_split(char *str);
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
void	ft_exit(void);
void	ft_echo(void);

/* utils */
/*		chore_utils		*/
int		is_same_string(char *str1, char *str2);
void	*safe_malloc(size_t size);

/*		env_utils		*/
void	split_env(t_env *env_node, char **env, int i);
void	env_linked_list(char **env);
t_env 	*get_env_by_key(char *key);
char	*get_env_value_by_key(char *key);
int		env_key_valid_checker(char *str);
t_token	*get_token_head(t_token *token);

/*		free_utils		*/
void	safe_free(void *p);
void    free_all(char *replaced_input, char **splitted_input);

/*		replace_dollar	*/
char	*append_buffer_under_dollar(char *save, char const *buffer);
char	*append_buffer_under_single_quote(char *save, char const *buffer);
char	*append_single_quote(char *input_buffer, char *input_ptr, int single_quote_len);
char	*append_buffer_after_all(char *save, char const *buffer);
int		is_dollar_replacement_end_condition(char c);
int		get_env_len(char *str);
int		get_single_quote_len(char *input_ptr);
int		get_under_single_quote_len(char *input_ptr);
int		get_under_dollar_len(char *input_ptr);
char	*replace_whole_input_dollar(char *input);

/*		other			*/
int		handle_quote(t_split *split, char *line);
void	print_error_message(char *str);
void	ft_error_exit(char *str);
void	print_error_two_messages(char *str1, char *str2);
t_env	*get_env_by_key(char *key);
int		env_key_valid_checker(char *str);
void	make_node_to_envp();
void	*ft_memccpy_under(void *dest, const void *src, int c, size_t n);
void	get_new_prompt();
void	heredoc_new_prompt();
int		is_white_space(char c);

/* parser */
void	set_process_list(t_process **ps_list, t_token *tk_lst);
int		count_pipe(t_token *tk_list);
void	init_pslist(t_process **lst, int cnt);
void	pslist_new(t_process **lst);
void	pslist_addback(t_process **lst);
void	init_process_struct(t_process **cmd_list);
void	cut_token_by_pipe(t_token **tk_list);
void	tk_listdelone(t_token **tk_list);
int		word_type_count(t_token *token);

/* executor */
/* 		executor.c	*/
void	executor(void);
void	execute_pipeline(void);
int		execute_single_cmdline(void);
int		execute_process(t_process *process, t_pipes *pipes);
int		execute_command(t_process *process);
void	execute_built_in(t_process *process);
int		is_built_in(t_process *ps_info);
/* 		heredoc.c 	*/
int		heredoc_to_temp_files(void);
void	make_temp_file(int file_index, char *delim);
/* 		is_func.c 	*/
int		is_accessable_command(t_token *cmd_list, char **paths);
char	*get_accessable_command(t_token *cmd_list, char **paths);
/* 		pipe.c	 	*/
void	init_pipe(t_pipes *p);
void	swap_pipe(t_pipes *p);
/* 		redirect.c 	*/
int		apply_redirection(char *filename, int mode);
int		apply_redirections(t_token *cmd_line);
void	restore_stdio(void);

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
