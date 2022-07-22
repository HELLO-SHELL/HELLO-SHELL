#include "../../include/minishell.h"

int	check_type(char *str)
{
	if (!ft_strcmp(str, "<"))
		return (TK_RDINPUT);
	if (!ft_strcmp(str, ">"))
		return (TK_RDOUTPUT);
	if (!ft_strcmp(str, "<<"))
		return (TK_HEREDOC);
	if (!ft_strcmp(str, ">>"))
		return (TK_APPEND);
	if (!ft_strcmp(str, "|"))
		return (TK_PIPE);
	return (TK_WORD);
}

t_token	*init_token_list(char **token_arr)
{
	t_token	*head;
	t_token	*curr;
	int		i;

	i = 0;
	if (!token_arr)
		exit(EXIT_FAILURE);
	curr = malloc(sizeof(t_token*));
	while (token_arr[i])
	{
		if (i == 0)
			head = curr;
		curr->str = token_arr[i];
		curr->type = check_type(token_arr[i]);
		curr->prev = NULL;
		if (token_arr[i+1])
		{
			curr->next = malloc(sizeof(t_token*));
			curr = curr->next;
		}
		else
			curr->next = NULL;
		i++;
	}
	curr = head;
	while (curr)
	{
		if (curr->next)
			curr->next->prev = curr;
		curr = curr->next;
	}
	return (head);
}
