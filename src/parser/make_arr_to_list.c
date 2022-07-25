#include "../../include/minishell.h"

static void	check_and_set_type(t_token *lst)
{
	if (!ft_strcmp(lst->value, "<"))
		lst->type = TK_RDINPUT;
	else if (!ft_strcmp(lst->value, ">"))
		lst->type =  TK_RDOUTPUT;
	else if (!ft_strcmp(lst->value, "<<"))
		lst->type =  TK_HEREDOC;
	else if (!ft_strcmp(lst->value, ">>"))
		lst->type =  TK_APPEND;
	else if (!ft_strcmp(lst->value, "|"))
		lst->type =  TK_PIPE;
	else if (lst->prev && (lst->prev->type == TK_RDOUTPUT \
	|| lst->prev->type == TK_RDINPUT || lst->prev->type == TK_APPEND))
		lst->type = TK_FILE;
	else if (lst->prev && lst->prev->type == TK_HEREDOC)
		lst->type = TK_DELIM;
	else
		lst->type = TK_WORD;
}

static void insert_first_into_list(t_token **lst, char *str)
{
	t_token *temp;

	temp = malloc(sizeof(t_token));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->type = 0;
	temp->value = str;
	temp->next = NULL;
	temp->prev = NULL;
	check_and_set_type(temp);
	*lst = temp;
}

static void	insert_str_into_list_back(t_token **lst, char *str)
{
	t_token *temp;

	temp = malloc(sizeof(t_token));
	if (!temp)
		exit(EXIT_FAILURE);
	temp->type = 0;
	temp->value = str;
	temp->next = NULL;
	temp->prev = *lst;
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
	free(str);
	str = NULL;
}

t_token	*set_token_list(char **token_arr)
{
	t_token	*token_list_head;

	if (!token_arr || !*token_arr)
		exit(EXIT_FAILURE);
	set_str_into_list(&token_list_head, token_arr);
	token_list_head = get_token_head(token_list_head);
	return (token_list_head);
}
