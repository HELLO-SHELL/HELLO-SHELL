#include "../../include/minishell.h"

int	export_error_check(t_token *token)
{
	t_token	*curr;

	curr = token;
	if (curr->next != NULL)
	{
		if (curr->value[0] == '='
			|| ft_isdigit(curr->value[0]) || curr->value[0] == '-')
			return (1);
	}
	else if (curr->value[0] == '='
			|| ft_isdigit(curr->value[0]) || curr->value[0] == '-')
			return (1);
	return (0);
}
// export: usage: export [-nf] [name[=value] ...] or export -p
void	ft_export(t_node *minishell)
{
	t_list	*curr;
	t_token *token;
	t_env	*env_node;
	char *key;
	char *value;

	curr = minishell->env_list;
	token = minishell->token_list;
	if (token->next == NULL)
	{
		while (curr->next)
		{
			// value 에 값이 없으면 다음으로 넘어감
			if (!strchr(((t_env *)(curr->content))->value, 0))
				curr = curr->next;
			else
			{
				printf("declare -x %s=%s\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);	
				curr = curr->next;
			}
		}
		printf("declare -x %s=%s\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
	}
	else
	{
		while (token->next)
		{
			if (export_error_check(token->next))
			{
				token = token->next;
                write(2,"HELLO-SHELL: `", 14);
                write(2, token->value, ft_strlen(token->value));
                write(2, "': command not found\n", 22);
			}
			else
			{
				env_node = malloc(sizeof(t_env));
				key = ft_substr(token->next->value, 0, ft_strchr(token->next->value, '=') - token->next->value);
				value = ft_substr(ft_strchr(token->next->value, '=') + 1, 0, ft_strlen(ft_strchr(token->next->value, '=')));
				env_node->key = key;
				env_node->value = value;
				ft_lstadd_back(&(minishell->env_list), ft_lstnew(env_node));
				token = token->next;
			}
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