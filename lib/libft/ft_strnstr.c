/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 21:44:23 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/06 14:01:21 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*hc_haystack;
	size_t	i;
	size_t	j;

	hc_haystack = (char *)haystack;
	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return (hc_haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + j] == needle[j]
			&& haystack[i + j] != '\0' && (i + j) < len)
			j++;
		if (needle[j] == '\0')
			return (hc_haystack + i);
		j = 0;
		i++;
	}
	return (0);
}
