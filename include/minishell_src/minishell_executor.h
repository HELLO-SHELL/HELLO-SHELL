#ifndef MINISHELL_EXECUTOR_H
# define MINISHELL_EXECUTOR_H

/* executor */
/* 		executor.c	*/
void	executor(void);
int		execute_pipeline(void);
void	execute_single_cmdline(void);
void	execute_process(t_process *process, t_pipes *pipes);
void	execute_command(t_process *process);
int		execute_built_in(t_process *process);
int		is_built_in(t_process *ps_info);
void	kill_all_childs(int input);
void	kill_all_child(int input);
/*		check.c		*/
int		check_file_type(const char *command);
/* 		heredoc.c 	*/
int		execute_heredoc(void);
void	make_temp_file(int file_index, char *delim);
/* 		is_func.c 	*/
char	*get_accessable_command(const char *command, char **paths);
char	*get_accessable_joined_command(const char *command, char **paths);
int		is_argv_null(char **argv);
int		is_heredoc_error(void);
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
pid_t	get_last_pid(void);
int		wait_child(pid_t pid);
int		signal_print(int status);
int		trans_status(int status);

#endif
