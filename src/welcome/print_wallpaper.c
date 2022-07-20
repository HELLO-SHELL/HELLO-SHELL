#include "../../include/minishell.h"

void	print_wallpaper(void)
{
	int		fd;
	char	*line;
	int		dup_result;

	fd = open("./assest/wallpaper", O_RDONLY);
	if (fd < 0)
		return ;
	close(fd);
}