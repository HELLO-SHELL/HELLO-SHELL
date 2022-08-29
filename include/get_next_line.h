/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:44:05 by seongyle          #+#    #+#             */
/*   Updated: 2022/08/29 18:27:29 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_gnl_list
{
	int					fd;
	char				*save;
	struct s_gnl_list	*next;
	struct s_gnl_list	*prev;
}	t_gnl_list;

char	*get_next_line(int fd);
void	*delete_node(t_gnl_list **node);
char	*append_buffer(char *save, char const *buffer);
size_t	ft_gnl_strlen(char const *s);
char	*ft_gnl_strchr(char const *s, int c);
size_t	ft_gnl_strlcpy(char *dst, char const *src, size_t dstsize);

#endif
