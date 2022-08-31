/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_executor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:32:09 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/31 11:48:16 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_EXECUTOR_H
# define MINISHELL_EXECUTOR_H

/* executor */
/* 		executor.c	*/
void	executor(void);
int		execute_pipeline(void);
void	execute_single_cmdline(void);
void	execute_process(t_process *process, t_pipes *pipes);
void	execute_command(t_process *process);

/*		kill_all_childs.c	*/
void	kill_all_childs(int input);
void	kill_all_child(int input);
/*		check.c		*/
int		check_file_type(const char *command);

/* 		heredoc.c 	*/
int		execute_heredoc(void);
void	unlink_all_tempfiles(void);

/* 		is_func.c 	*/
char	*get_accessable_command(const char *command, char **paths);
int		is_argv_null(char **argv);
int		is_heredoc_error(void);

/* 		pipe.c	 	*/
void	init_pipe(t_pipes *p);
void	swap_pipe(t_pipes *p);

/* 		redirect.c 	*/
int		apply_redirections(t_token *cmd_line);
void	restore_stdio(void);

/* 		safe_func.c	*/
void	safe_dup2(int fd, int to_fd);
int		safe_openfile(char *filename, int mode);
void	safe_close_pipes(t_pipes *p);
void	safe_close_pipe(int *fd);

/*		wait.c		*/
int		wait_childs(void);
int		wait_child(int pid);
pid_t	get_last_pid(void);
int		signal_print(int status);
int		trans_status(int status);

#endif
