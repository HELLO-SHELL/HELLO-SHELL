#include "../../include/minishell.h"

int	export_check_error(t_token *token)
{
	/**************************************************************
	// 따옴표 체크
	// 키 따옴표
	// 1. 따옴표 출력하면 안됨
	// 2. 따옴표 안에 공백있으면 안됨
	// 3. 따옴표 여러개 사이에 공백이 없으면 하나의 문자열로 합쳐짐
	// value 따옴표
	// 1. 띄어쓰기도 포함해서 하나의 벨루가 됨
	 *************************************************************/
	// if (export_check_first_char(token));
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

// void	export_check_argu(t_node minishell, t_token *token)
// {}

void	ft_export(t_node *minishell)
{
	t_token *token;
	t_env	*env_node;
	

	token = minishell->token_list;
	if (token->next == NULL)
		export_display(minishell);
	else
	{
		while (token->next)
		{
		// 	export_check_argu();
			if (export_check_error(token))
			{
				token = token->next;
                write(2,"HELLO-SHELL: `", 14);
                write(2, token->value, ft_strlen(token->value));
                write(2, "': command not found\n", 22);
			}
			else
			{
				// export_get_lst();
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
