/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:15:09 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:05 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

void	*safe_malloc(size_t size)
{
	void	*allocated_ptr;

	allocated_ptr = malloc(size);
	if (!allocated_ptr)
		error_exit("malloc failed");
	ft_bzero(allocated_ptr, size);
	return (allocated_ptr);
}
