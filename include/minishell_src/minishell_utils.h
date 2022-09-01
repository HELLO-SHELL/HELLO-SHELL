/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:38:53 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/01 17:02:24 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_UTILS_H
# define MINISHELL_UTILS_H

/* utils */
/*		cd_utils.c		*/
int		is_path_only_home(t_token *cmd_list);
int		is_path_pass_home(t_token *cmd_list);
int		set_path_to_home(char **path);
int		set_path_at_home(t_token *cmd_list, char **path);
int		set_path_to_input(t_token *cmd_list, char **path);

/*		executor_built_in.c		*/
int		execute_built_in(t_process *process);
int		is_built_in(t_process *ps_info);
int		check_cmd(char *word);

/*		export_utils.c		*/
void	update_value_when_overlap(t_env *temp, char *str);
t_env	*get_overlap_env(char *key);

/*		env_utils		*/
void	split_env(t_env *env_node, char **env, int i);
void	env_linked_list(char **env);
t_env	*get_env_by_key(char *key);
char	*get_env_value_by_key(char *key);
t_token	*get_token_head(t_token *token);
int		env_key_valid_checker(char *str);
void	make_node_to_envp(void);

/*		chore_utils		*/
int		quote_validator(char *input);
int		is_same_string(char *str1, char *str2);
void	*safe_malloc(size_t size);
int		is_white_space(char c);

/*		free_utils		*/
void	safe_free(void *p);
void	free_all(void);
void	free_token_list(t_token *token);

/*		replace_dollar	*/
/*		replace_dollar_append_utils.c	*/
char	*append_buffer_under_dollar(char *save, char const *buffer);
char	*append_buffer_under_single_quote(char *save, char const *buffer);
char	*append_single_quote(char *input_buffer,
			char *input_ptr,
			int single_quote_len);
char	*append_buffer_after_all(char *save, char const *buffer);
char	*append_buffer_single_dollar(char *save);
/*		replace_dollar_is_utils.c		*/
int		is_only_dollar(char *input_ptr);
int		is_symbol_in_dollar_replace(char *input_ptr);
int		is_dollar_replacement_end_condition(char c);
/*		replace_dollar_len_utils.c		*/
int		get_env_len(char *str);
int		get_single_quote_len(char *input_ptr);
int		get_under_single_quote_len(char *input_ptr);
int		get_under_dollar_len(char *input_ptr);
/*		replace_dollar_utils.c		*/
void	r_handle_single_quote(char **input_buffer, char **input_ptr);
void	r_handle_dollar(char **input_buffer, char **input_ptr);
void	make_dollar_replaced_input(char **input_buffer, char **input_ptr);
char	*replace_dollar(char *input_buffer, char *temp);
/*		replace_dollar.c		*/
char	*replace_whole_input_dollar(char *input);
char	*replace_dollar_in_heredoc(char *input);

/*		other	*/
/*		ft_error.c	*/
void	print_error_message(char *str);
void	error_exit(char *str);
void	print_error_two_messages(char *str1, char *str2);
void	error_two_exit(char *str1, char *str2);
void	error_two_exit_status(int status, char *str1, char *str2);
/*		signal.c	*/
void	get_new_prompt(int input);
void	heredoc_new_prompt(int input);
/*		last_status.c	*/
void	set_last_status(int status);

/*		welcome	*/
void	print_wallpaper(void);

#endif
