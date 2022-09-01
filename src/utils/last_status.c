/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_status.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:08:22 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:09 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	set_last_status(int status)
{
	free(g_minishell_info.last_status);
	g_minishell_info.last_status = ft_itoa(status);
}
