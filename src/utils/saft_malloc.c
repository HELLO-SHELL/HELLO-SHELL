#include "../../include/libft.h"

void    *safe_malloc(size_t size)
{
    void    *allocated_ptr;

    allocated_ptr = malloc(size);
    if (!allocated_ptr)
        ft_error("malloc failed");
    return (allocated_ptr);
}
