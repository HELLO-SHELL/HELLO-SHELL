/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:15:18 by jimin             #+#    #+#             */
/*   Updated: 2022/08/29 18:15:19 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_file_type(const char *command)
{
	struct stat	file_stat;

	if (stat(command, &file_stat))
		return (NOTFOUND);
	if ((file_stat.st_mode & S_IFMT) == S_IFDIR)
		return (DIRECTORY);
	return (COMMON_FILE);
}
