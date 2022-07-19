/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 16:10:11 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/06 14:02:35 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*result;
	size_t		i;

	i = ft_strlen(str);
	if (!c)
		return (((char *)str + i));
	result = 0;
	while (*str)
	{
		if (*str == (unsigned char)c)
			result = str;
		str++;
	}
	return ((char *)result);
}
