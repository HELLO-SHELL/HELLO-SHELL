/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyungsle <kyungsle@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 20:28:15 by kyungsle          #+#    #+#             */
/*   Updated: 2021/12/05 12:33:06 by kyungsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_set_result(int n, char *result, int *i)
{
	if (n >= 10)
	{
		ft_set_result(n / 10, result, i);
	}
	result[(*i)++] = (n % 10) + '0';
	return (0);
}

static int	ft_get_size(int n)
{
	int	result;

	result = 0;
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		n /= 10;
		result++;
	}
	return (result + 1);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*result;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	result = malloc(sizeof(char) * ft_get_size(n) + (n < 0));
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[i++] = '-';
		n *= -1;
	}
	ft_set_result(n, result, &i);
	result[i] = '\0';
	return (result);
}
