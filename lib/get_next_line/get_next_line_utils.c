/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 13:34:15 by seongyle          #+#    #+#             */
/*   Updated: 2022/08/29 18:21:11 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*delete_node(t_gnl_list **node)
{
	free((*node)->save);
	(*node)->prev->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->prev = (*node)->prev;
	free(*node);
	*node = NULL;
	return (NULL);
}

char	*ft_gnl_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

char	*append_buffer(char *save, char const *buffer)
{
	char	*new;

	if (buffer == NULL)
		return (NULL);
	else if (save == NULL && buffer)
	{
		new = malloc(ft_gnl_strlen(buffer) + 1);
		if (!new)
			return (NULL);
		ft_gnl_strlcpy(new, buffer, ft_gnl_strlen(buffer) + 1);
		return (new);
	}
	new = malloc(ft_gnl_strlen(save) + ft_gnl_strlen(buffer) + 1);
	if (!new)
		return (NULL);
	ft_gnl_strlcpy(new, save, ft_gnl_strlen(save) + 1);
	ft_gnl_strlcpy(new
		+ ft_gnl_strlen(save), buffer, ft_gnl_strlen(buffer) + 1);
	free(save);
	save = NULL;
	return (new);
}

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (dst_size)
	{
		while (src != dst && src[i] && i < dst_size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_gnl_strlen(src));
}
