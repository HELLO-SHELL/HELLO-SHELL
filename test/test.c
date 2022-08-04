#include <stdio.h>
#include "../include/minishell.h"

int	main(void)
{
	char *c = "abcd=";
	char *key;
	char *value;

	key = ft_substr(c, 0, ft_strchr(c, '=') - c);
	value = ft_substr(ft_strchr(c, '=') + 1, 0, ft_strlen(ft_strchr(c, '=')));

	printf("%s\n", ft_strchr(c, '='));
	printf("%s\n", c);
	printf("%ld\n", ft_strchr(c, '=') - c);
	printf("key = %s\n", key);
	printf("value = %s\n", value);
}
