#include "../../../include/minishell.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	void	*p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
		return (ft_memcpy(dest, src, p - src + 1) + (p - src + 1));
	ft_memcpy(dest, src, n);
	return (NULL);
}