/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 23:39:01 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/05 14:23:42 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int ch, size_t count)
{
	unsigned char	*str;
	size_t			i;

	str = dest;
	i = 0;
	while (i < count)
	{
		str[i] = (unsigned char)ch;
		i++;
	}
	return (dest);
}
