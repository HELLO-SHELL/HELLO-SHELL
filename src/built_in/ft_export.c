#include "../../include/minishell.h"

void	ft_export(t_node *minishell)
{
	t_list	*curr;
	t_token *token;

	curr = minishell->env_list;
	token = minishell->token_list;

	// 두번째 value 체크
	if (token->next == NULL)
	{
		while (curr->next)
		{
			printf("declare -x %s=%s\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);	
			curr = curr->next;
		}
	}
}
	// int	len;
	// t_list	*sort_list;

	// len = ft_lstsize(sort_list);
	// sort_list = ft_sort_list(sort_list, 0, len);
	// sort_list = minishell->env_list;

// t_list	*ft_sort_list(t_list *sort_list, int min, int max)
// {
// 	int	mid;
	
// 	mid = max / 2;
// 	if (mid > 0)
// 		ft_sort_list(sort_list, min, max);
// 	else
// 	{
// 		sort_left(sort_list);
// 		sort_right(sort_list);
// 	}
// }