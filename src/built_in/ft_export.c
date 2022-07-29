#include "../../include/minishell.h"

int	export_error_check(t_token *token)
{
	t_token	*curr;

	curr = token->next;
	if (curr->next != NULL)
	{
		if (ft_isalpha(curr->value[0]) || curr->value[0] == '_')
			return (0);
	}
	else if (ft_isalpha(curr->value[0]) || curr->value[0] == '_')
			return (0);
	return (1);
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
            // export a-1 처럼 중간에 숫자와 영문이 아닌것
			if (((t_env *)(curr->content))->value == NULL)
				printf("declare -x %s\n", ((t_env *)(curr->content))->key);	
			else
				printf("declare -x %s=\"%s\"\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
			curr = curr->next;
		}
		if (((t_env *)(curr->content))->value == NULL)
			printf("declare -x %s\n", ((t_env *)(curr->content))->key);	
		else
			printf("declare -x %s=\"%s\"\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
	}
	else
	{
		while (token->next)
		{
			if (export_error_check(token))
			{
				token = token->next;
                write(2,"HELLO-SHELL: `", 14);
                write(2, token->value, ft_strlen(token->value));
                write(2, "': command not found\n", 22);
			}
			else
			{
				// '=' 찾을 때
				char *str;
				// value 초기화
				env_node = malloc(sizeof(t_env));
				str = ft_strchr(token->next->value, '=');
				key = ft_substr(token->next->value, 0, str - token->next->value);
				if (str)
					value = ft_substr(str + 1, 0, ft_strlen(str));
				else if (str == NULL)
					value = 0;
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