/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 20:53:49 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/05 14:23:13 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*hc_dest;
	unsigned char	*hc_src;

	hc_dest = (unsigned char *)dest;
	hc_src = (unsigned char *)src;
	if (hc_dest > hc_src)
	{
		hc_dest += (n - 1);
		hc_src += (n - 1);
		while (n-- > 0)
			*(hc_dest--) = *(hc_src--);
	}
	else if (hc_dest < hc_src)
		dest = ft_memcpy(dest, src, n);
	return (dest);
}
