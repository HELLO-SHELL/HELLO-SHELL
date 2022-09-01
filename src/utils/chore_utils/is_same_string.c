/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:14:49 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:18:03 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

static size_t	longer_strlen(char *str1, char *str2)
{
	size_t	str1_len;
	size_t	str2_len;

	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	if (str1_len <= str2_len)
		return (str2_len);
	return (str1_len);
}

int	is_same_string(char *str1, char *str2)
{
	size_t	size;

	if (!str1 || !str2)
		return (0);
	size = longer_strlen(str1, str2);
	if (!ft_strncmp(str1, str2, size))
		return (1);
	return (0);
}
