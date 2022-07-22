#include "../../include/minishell.h"

int	check_type(char *str)
{
	if (!ft_strcmp(str, '<'))
		return (TK_RDINPUT);
	if (!ft_strcmp(str, '>'))
		return (TK_RDOUTPUT);
	if (!ft_strcmp(str, '<<'))
		return (TK_HEREDOC);
	if (!ft_strcmp(str, '>>'))
		return (TK_APPEND);
	if (!ft_strcmp(str, '|'))
		return (TK_PIPE);
	return (TK_WORD);
}

void	move_arr_to_list(t_token *curr, char *str)
{
	curr = malloc(sizeof(t_token*));
	curr->str = str;
	curr->type = check_type(str);
}

t_token	*init_token_list(char **token_arr)
{
	t_token	*head;
	t_token	*curr;
	int		i;

	i = 0;
	curr = head;
	curr -> prev = NULL;
	if (!token_arr)
		exit(EXIT_FAILURE);
	while (token_arr[i])
	{
		move_arr_to_list(curr, token_arr[i]);
		curr = curr->next;
		i++;
	}
	return (head);
}
