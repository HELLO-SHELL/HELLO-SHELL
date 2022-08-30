/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:58:55 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/31 02:08:59 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	export_check_error(t_token *token)
{
	t_token	*curr;
	int		i;

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
			printf("declare -x %s=\"%s\"\n",
				((t_env *)(curr->content))->key,
				((t_env *)(curr->content))->value);
		curr = curr->next;
	}
}

static void	export_get_list(t_token *token)
{
	char	*key;
	char	*value;
	char	*str;
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

int	ft_export(t_token *token)
{
	if (token->next == NULL)
		export_display();
	else
	{
		while (token->next)
		{
			if (export_check_error(token))
			{
				token = token->next;
				print_error_two_messages(token->value,
					"': not a valid identifier");
				return (EXIT_FAILURE);
			}
			else
			{
				export_get_list(token);
				token = token->next;
			}
		}
	}
	return (EXIT_SUCCESS);
}
