#include "../../include/minishell.h"

static int	is_border(char c)
{
	if (c == '/' || c == '|' || c == '\\' || c == '-')
		return (1);
	return (0); // need to change enum!
}

static int	is_star(char c)
{
	if (c == '*' || c == '.')
		return (1);
	return (0);
}

void	print_wallpaper(void)
{
	int		fd;
	char	*line;
	size_t	i;

	fd = open("./assest/wallpaper", O_RDONLY);
	if (fd < 0)
		return ;
	while (1) // need to change enum! 
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = 0;
		while (i < ft_strlen(line))
		{
			if (is_border(line[i]))
				printf("%s%c%s", WHT, line[i], COLOR_RESET);
			else if (is_star(line[i]))
				printf("%s%c%s", YEL, line[i], COLOR_RESET);
			else if (ft_isalpha(line[i]))
				printf("%s%c%s", CYN, line[i], COLOR_RESET);
			else if (ft_isdigit(line[i]))
				printf("%s%c%s", BLU, line[i], COLOR_RESET);
			else
				printf("%s%c%s", BLKB, line[i], COLOR_RESET);
			i++;
		}
		free(line);
	}
	printf("\n");
	close(fd);
}
