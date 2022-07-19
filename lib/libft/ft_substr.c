/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:26:10 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/06 20:39:17 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	s_len;
	size_t	alloc_size;

	s_len = ft_strlen(s);
	if (s_len <= (size_t)start || len == 0 || s_len == 0)
		return (ft_strdup(""));
	if (s_len > start + len)
		alloc_size = len + 1;
	else
		alloc_size = (s_len - start) + 1;
	result = (char *)malloc((alloc_size) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, &s[start], len + 1);
	return (result);
}
