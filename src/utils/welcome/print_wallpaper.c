/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wallpaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:07:53 by jaekim            #+#    #+#             */
/*   Updated: 2022/09/01 17:03:41 by jaekim           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

static int	is_border(char c)
{
	if (c == '/' || c == '|' || c == '\\' || c == '-')
		return (TRUE);
	return (FALSE);
}

static int	is_star(char c)
{
	if (c == '*' || c == '.')
		return (TRUE);
	return (FALSE);
}

void	draw_wallpaper(char *line)
{
	size_t	i;

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
}

void	init_wallpaper(int fd)
{
	char	*line;

	line = NULL;
	while (TRUE)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		draw_wallpaper(line);
		free(line);
	}
	printf("\n");
}

void	print_wallpaper(void)
{
	int		fd;

	fd = open("./assets/wallpaper", O_RDONLY);
	if (fd < 0)
		return ;
	init_wallpaper(fd);
	close(fd);
}
