/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:15:09 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:15:10 by jaekim           ###   ########.fr       */
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
