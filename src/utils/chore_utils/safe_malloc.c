<<<<<<< HEAD:src/utils/chore_utils/safe_malloc.c
#include "../../../include/minishell.h"

void *safe_malloc(size_t size)
{
	void	*allocated_ptr;

	allocated_ptr = malloc(size);
	if (!allocated_ptr)
		ft_error_exit("malloc failed");
	return (allocated_ptr);
}
=======
#include "../../include/minishell.h"

void *safe_malloc(size_t size)
{
	void	*allocated_ptr;

	allocated_ptr = malloc(size);
	if (!allocated_ptr)
		ft_error_exit("malloc failed");
	ft_bzero(allocated_ptr, size);
	return (allocated_ptr);
}
>>>>>>> 83d1633d869fddeb932879032772c56df3a73849:src/utils/safe_malloc.c
