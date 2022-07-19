/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:33:20 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/05 14:23:19 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*hc_dest;
	unsigned char	*hc_src;
	size_t			i;

	hc_dest = (unsigned char *)dest;
	hc_src = (unsigned char *)src;
	i = 0;
	if (src == dest)
		return (dest);
	while (i < n)
	{
		hc_dest[i] = hc_src[i];
		i++;
	}
	return (dest);
}
