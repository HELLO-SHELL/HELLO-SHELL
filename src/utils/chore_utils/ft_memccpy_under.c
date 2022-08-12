#include "../../../include/minishell.h"

void	*ft_memccpy_under(void *dest, const void *src, int c, size_t n)
{
	void	*p;

	p = ft_memchr(src, c, n);
	if (p != NULL)
		return (ft_memcpy(dest, src, p - src) + (p - src));
	ft_memcpy(dest, src, n);
	return (NULL);
}