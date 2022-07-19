/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 15:48:16 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/06 14:01:30 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*temp_start;
	char	*temp_end;
	int		i;

	temp_start = (char *)s1;
	temp_end = (char *)(s1 + ft_strlen(s1) - 1);
	i = 0;
	while (temp_start < temp_end && ft_memchr(set, *temp_start, ft_strlen(set)))
		temp_start++;
	while (temp_start <= temp_end && ft_memchr(set, *temp_end, ft_strlen(set)))
		temp_end--;
	result = (char *)malloc((temp_end - temp_start + 2) * sizeof(char));
	if (!result)
		return (NULL);
	while (temp_start <= temp_end)
		result[i++] = *(temp_start++);
	result[i] = '\0';
	return (result);
}
