#include "../../../include/minishell.h"

t_env	*get_env_by_key(char *key)
{
    t_list  *temp;

    temp = g_minishell.env_list;
    while (temp)
		{
			if (is_same_string(((t_env *)temp->content)->key, key))
				return ((t_env *)temp->content);
			temp = temp->next;
		}
    return (NULL);
}

char	*get_env_value_by_key(char *key)
{
    t_list  *temp;

    temp = g_minishell.env_list;
    while (temp)
		{
			if (is_same_string(((t_env *)temp->content)->key, key))
				return (((t_env *)(temp->content))->value);
			temp = temp->next;
		}
    return (NULL);
}