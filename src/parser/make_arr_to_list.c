/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr_to_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:10:30 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/30 13:08:28 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	check_and_set_type(t_token *lst)
{
	if (is_same_string(lst->value, "<"))
		lst->type = TK_RDINPUT;
	else if (is_same_string(lst->value, ">"))
		lst->type = TK_RDOUTPUT;
	else if (is_same_string(lst->value, "<<"))
		lst->type = TK_HEREDOC;
	else if (is_same_string(lst->value, ">>"))
		lst->type = TK_APPEND;
	else if (is_same_string(lst->value, "|"))
		lst->type = TK_PIPE;
	else if (lst->prev && (lst->prev->type == TK_RDOUTPUT \
	|| lst->prev->type == TK_RDINPUT || lst->prev->type == TK_APPEND))
		lst->type = TK_FILE;
	else if (lst->prev && lst->prev->type == TK_HEREDOC)
		lst->type = TK_DELIM;
	else
		lst->type = TK_WORD;
}

static void	insert_first_into_list(t_token **lst, char *str)
{
	t_token	*temp;

	temp = safe_malloc(sizeof(t_token));
	temp->type = 0;
	temp->value = ft_strdup(str);
	temp->next = NULL;
	temp->prev = NULL;
	if (temp->value == NULL)
		error_exit("malloc error");
	check_and_set_type(temp);
	*lst = temp;
}

static void	insert_str_into_list_back(t_token **lst, char *str)
{
	t_token	*temp;

	temp = safe_malloc(sizeof(t_token));
	temp->type = 0;
	temp->value = ft_strdup(str);
	temp->next = NULL;
	temp->prev = *lst;
	if (temp->value == NULL)
		error_exit("malloc error");
	check_and_set_type(temp);
	(*lst)->next = temp;
	(*lst) = (*lst)->next;
}

static void	set_str_into_list(t_token **lst, char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
			insert_first_into_list(lst, str[i]);
		else
			insert_str_into_list_back(lst, str[i]);
		i++;
	}
}

t_token	*make_token_list(char **token_arr)
{
	t_token	*token_list_head;
	int		idx;

	idx = 0;
	set_str_into_list(&token_list_head, token_arr);
	token_list_head = get_token_head(token_list_head);
	while (token_arr[idx])
	{
		safe_free(token_arr[idx]);
		token_arr[idx] = NULL;
		idx++;
	}
	safe_free(token_arr);
	token_arr = NULL;
	return (token_list_head);
}
