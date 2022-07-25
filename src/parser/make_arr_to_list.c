#include "../../include/minishell.h"

void	check_type(t_token *lst)
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

void	insert_str_into_list(t_token *lst, char **str)
{
	int	i;

	i = 0;
	lst->prev = NULL;
	while (str[i])
	{
		lst->value = str[i];
		check_type(lst);
		if (str[i+1])
		{
			lst->next = malloc(sizeof(t_token*));
			if (!(lst->next))
				exit(EXIT_FAILURE);
			lst->next->prev = lst;
			lst = lst->next;
		}
		else
			lst->next = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

t_token	*init_token_list(char **token_arr)
{
	t_token	*head;
	t_token	*curr;

	if (!token_arr || !*token_arr)
		exit(EXIT_FAILURE);
	curr = malloc(sizeof(t_token *));
	if (!curr)
		exit(EXIT_FAILURE);
	head = curr;
	insert_str_into_list(curr, token_arr);
	return (head);
}
