#include "../../include/minishell.h"

int	export_check_error(t_token *token)
{
	/**************************************************************
	따옴표 체크
	
	따옴표 함수
	1. 맨 앞이 쿼트면,
	쿼트 개수 짝수인지 파악하기
	(홀수면 에러)

	2. 언더바 문자 시작하는지 파악(해놓음)

	3. 쿼트부터 문자 언더바 숫자만 개수 파악하기
	(0이면 에러)
	- 기존 것 프리

	4. 개수 크기로 할당해서 값 넣기
	(연속이 아니라서 주소로 안됨)

	value 따옴표
	1. 띄어쓰기도 포함해서 하나의 벨루가 됨
	2. 백슬래쉬는 예외 (\)
	 *************************************************************/
	// if (export_check_quotes(token))
	t_token	*curr;
	int	i;

	i = 0;
	curr = token->next;
	if (!(ft_isalpha(curr->value[i]) || curr->value[i] == '_'))
		return (1);
	i++;
	while (curr->value[i] != '=' && curr->value[i] != '\0')
	{
		if (ft_isalnum(curr->value[i]) || curr->value[i] == '_')
			i++;
		else
			return (1);	
	}
	return (0);
}

void	export_display(t_minishell *minishell)
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

static t_env	*get_overlap_env(t_list *env_list, char *key)
{
	t_env	*temp;
	
	temp = get_env_by_key(env_list, key);
	if (temp)
	{
		free(key);
		key = NULL;
		return (temp);
	}
	return (NULL);
}

static void	update_value_when_overlap(t_env *temp, char *str)
{
	t_env	*updated_env;

	if (temp == NULL || str == NULL)
		return ;
	updated_env = temp;
	free(updated_env->value);
	updated_env->value = ft_substr(str + 1, 0, ft_strlen(str));
}

void	export_get_list(t_minishell *minishell, t_token *token)
{
	char *key;
	char *value;
	char *str;
	t_env	*env_node;
	t_env	*overlap_env;

	str = ft_strchr(token->next->value, '=');
	key = ft_substr(token->next->value, 0, str - token->next->value);
	overlap_env = get_overlap_env(minishell->env_list, key);
	if (overlap_env)
		return (update_value_when_overlap(overlap_env, str));
	if (str == NULL)
		value = 0;
	else 
		value = ft_substr(str + 1, 0, ft_strlen(str));
	env_node = safe_malloc(sizeof(t_env));
	env_node->key = key;
	env_node->value = value;
	ft_lstadd_back(&(minishell->env_list), ft_lstnew(env_node));
}

void	ft_export(t_minishell *minishell)
{
	t_env	*env_node;
	t_token *token;	

	token = minishell->ps_list.cmd_line;
	if (token->next == NULL)
		export_display(minishell);
	else
	{
		while (token->next)
		{
			if (export_check_error(token))
			{
				token = token->next;
                write(2,"HELLO-SHELL: ", 14);
                write(2, token->value, ft_strlen(token->value));
                write(2, "': command not found\n", 22);
			}
			else
			{
				export_get_list(minishell, token);
				token = token->next;
			}
		}
	}
}
