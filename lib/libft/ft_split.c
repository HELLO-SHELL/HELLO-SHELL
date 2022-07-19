/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:47:25 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/07 17:59:48 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlen_exsep(char const *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] != charset))
		i++;
	return (i);
}

static int	ft_word_count(char const *str, char charset)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while ((str[i] == charset) && str[i] != '\0')
			i++;
		if (str[i] != '\0')
			count++;
		while ((str[i] != charset) && str[i] != '\0')
			i++;
	}
	return (count);
}

static char	*ft_set_result(char const *str, char charset)
{
	int		str_len;
	int		i;
	char	*str_arr;

	i = 0;
	str_len = ft_strlen_exsep(str, charset);
	str_arr = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!str_arr)
		return (NULL);
	while (i < str_len)
	{
		str_arr[i] = str[i];
		i++;
	}
	str_arr[i] = '\0';
	return (str_arr);
}

static int	ft_clean_result(char **result, int t_len, int i)
{
	int	idx;

	idx = 0;
	if (i < (t_len - 1) && !result[i])
	{
		while (idx < i)
		{
			free(result[idx]);
			result[idx++] = NULL;
		}
		free(result);
		result = NULL;
		return (1);
	}
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		t_len;
	int		i;

	i = 0;
	t_len = ft_word_count(s, c) + 1;
	result = (char **)malloc(sizeof(char *) * (t_len));
	if (!result)
		return (NULL);
	while (*s != '\0')
	{
		while (*s && (*s == c))
			s++;
		if (*s)
		{
			result[i] = ft_set_result(s, c);
			if (ft_clean_result(result, t_len, i++))
				return (NULL);
		}
		while (*s && (*s != c))
			s++;
	}
	result[i] = 0;
	return (result);
}
