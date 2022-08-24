#include "../../include/minishell.h"

int	export_check_error(t_token *token)
{
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

static void	export_display(void)
{
	t_list	*curr;

	curr = g_minishell_info.env_list;
	while (curr)
	{
		if (((t_env *)(curr->content))->value == NULL)
			printf("declare -x %s\n", ((t_env *)(curr->content))->key);
		else
			printf("declare -x %s=\"%s\"\n", ((t_env *)(curr->content))->key, ((t_env *)(curr->content))->value);
		curr = curr->next;
	}
}

static t_env	*get_overlap_env(char *key)
{
	t_env	*temp;
	
	temp = get_env_by_key(key);
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

static void	export_get_list(t_token *token)
{
	char *key;
	char *value;
	char *str;
	t_env	*env_node;
	t_env	*overlap_env;

	str = ft_strchr(token->next->value, '=');
	key = ft_substr(token->next->value, 0, str - token->next->value);
	overlap_env = get_overlap_env(key);
	if (overlap_env)
		return (update_value_when_overlap(overlap_env, str));
	if (str == NULL)
		value = 0;
	else 
		value = ft_substr(str + 1, 0, ft_strlen(str));
	env_node = safe_malloc(sizeof(t_env));
	env_node->key = key;
	env_node->value = value;
	ft_lstadd_back(&(g_minishell_info.env_list), ft_lstnew(env_node));
}

void	ft_export(void)
{
	t_token *token;	

	token = g_minishell_info.ps_list->cmd_line;
	if (token->next == NULL)
		export_display();
	else
	{
		while (token->next)
		{
			if (export_check_error(token))
			{
				token = token->next;
				ft_putstr_fd("HELLO-SHELL: `", STDERR_FILENO);
				ft_putstr_fd(token->value, STDERR_FILENO);
				ft_putendl_fd("': command not found", STDERR_FILENO);
			}
			else
			{
				export_get_list(token);
				token = token->next;
			}
		}
	}
}
