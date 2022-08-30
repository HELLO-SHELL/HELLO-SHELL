/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_parser.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:34:51 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:34:57 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_PARSER_H
# define MINISHELL_PARSER_H

/* parser */
void	set_process_list(t_process **ps_list, t_token *tk_lst);
int		count_pipe(t_token *tk_list);
void	init_pslist(t_process **lst, int cnt);
void	pslist_new(t_process **lst);
void	pslist_addback(t_process **lst);
void	init_process_struct(t_process **cmd_list);
void	cut_token_by_pipe(t_token **tk_list);
void	tk_listdelone(t_token **tk_list);
int		token_word_count(t_token *token);
int		check_token_error(t_token *token);
int		is_special_token(int type);
int		handle_quote(t_split *split, char *line);
char	**command_split(char *str);
int		count_split_size(char *str);
int		split_line(t_split *split, char *line);
t_token	*make_token_list(char **token_arr);

#endif
