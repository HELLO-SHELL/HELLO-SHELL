#include "../../include/minishell.h"

int	export_check_error(t_token *token)
{
	/**************************************************************
	key&value
	1. 띄어씌기 에러처리
	2. 중복 처리
	value 따옴표
	1. 백슬래쉬는 예외 (\)
	 *************************************************************/
	t_token	*curr;
	int	i;

	i = 0;
	curr = token->next;
	if (!(ft_isalpha(curr->value[i]) || curr->value[i] == '_'))
		return (1);
	i++;
	// if (export_check_argu(curr))
// 	return (1);
	while (curr->value[i] != '=' && curr->value[i] != '\0')
	{
		if (ft_isalnum(curr->value[i]) || curr->value[i] == '_')
			i++;
		else
			return (1);	
	}
	return (0);
}

void	export_display(t_node *minishell)
{
	t_list	*curr;

	curr = minishell->env_list;
	while (curr)
	{
		if (((t_env *)(curr->content))->value == NULL)
			printf("declare -x %s\n", ((t_env *)(curr->content))->key);
		else
			printf("declare -x %s=\"%s\"\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
		curr = curr->next;
	}
}

// void	export_get_key_value();

// void	export_get_list(t_node *minishell, t_token *token)
// {
// 	char *key;
// 	char *value;
// 	char *str;
// 	t_env	*env_node;

// 	env_node = malloc(sizeof(t_env));
// 	// export_get_key_value();
// 	str = ft_strchr(token->next->value, '='); //  =abcd
// 	key = ft_substr(token->next->value, 0, str - token->next->value);
// 	if (str)
// 		value = ft_substr(str + 1, 0, ft_strlen(str));
// 	else if (str == NULL)
// 		value = 0;
// 	env_node->key = key;
// 	env_node->value = value;
// 	ft_lstadd_back(&(minishell->env_list), ft_lstnew(env_node));
// 	token = token->next;
// }

void	ft_export(t_node *minishell)
{
	t_env	*env_node;
	t_token *token;	

	token = minishell->token_list;
	if (token->next == NULL)
		export_display(minishell);
	else
	{
		while (token->next)
		{
			if (export_check_error(token))
			{
				token = token->next;
                write(2,"HELLO-SHELL: `", 14);
                write(2, token->value, ft_strlen(token->value));
                write(2, "': command not found\n", 22);
			}
			else
			{
				// export_get_list(minishell, token);
				// '=' 찾을 때
				char *key;
				char *value;
				char *str;
				env_node = malloc(sizeof(t_env));
				// export_get_key_value();
				str = ft_strchr(token->next->value, '='); //  =abcd
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
