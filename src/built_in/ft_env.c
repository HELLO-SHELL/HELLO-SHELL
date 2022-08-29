/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:58:40 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 16:58:42 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_env(void)
{
	t_list	*env;

	env = g_minishell_info.env_list;
	while (env)
	{
		if (((t_env *)(env->content))->value != NULL)
			printf("%s=%s\n", ((t_env *)(env->content))->key,
				((t_env *)(env->content))->value);
		env = env->next;
	}
	return (EXIT_SUCCESS);
}
