#include "../../include/minishell.h"

static void	check_and_set_type(t_token *lst)
{
	if (is_same_string(lst->value, "<"))
		lst->type = TK_RDINPUT;
	else if (is_same_string(lst->value, ">"))
		lst->type =  TK_RDOUTPUT;
	else if (is_same_string(lst->value, "<<"))
		lst->type =  TK_HEREDOC;
	else if (is_same_string(lst->value, ">>"))
		lst->type =  TK_APPEND;
	else if (is_same_string(lst->value, "|"))
		lst->type =  TK_PIPE;
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
	t_token *temp;

	temp = safe_malloc(sizeof(t_token));
	temp->type = 0;
	temp->value = ft_strdup(str);
	temp->next = NULL;
	temp->prev = NULL;
	check_and_set_type(temp);
	*lst = temp;
}

static void	insert_str_into_list_back(t_token **lst, char *str)
{
	t_token *temp;

	temp = safe_malloc(sizeof(t_token));
	temp->type = 0;
	temp->value = ft_strdup(str);
	temp->next = NULL;
	temp->prev = *lst;
	check_and_set_type(temp);
	(*lst)->next = temp;
	(*lst) = (*lst)->next;
}

static int	set_str_into_list(t_token **lst, char **str)
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
	return (1);
}

t_token	*make_token_list(char **token_arr)
{
	t_token	*token_list_head;

	if (!token_arr || !*token_arr)
		exit(EXIT_FAILURE);
	if (set_str_into_list(&token_list_head, token_arr))
		token_list_head = get_token_head(token_list_head);
	else
		return (0);
	return (token_list_head);
}
