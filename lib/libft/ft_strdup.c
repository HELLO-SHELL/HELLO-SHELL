/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:28:16 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/06 14:00:26 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(str);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (0);
	while (str[i])
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
