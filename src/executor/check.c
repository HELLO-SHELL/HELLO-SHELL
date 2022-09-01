/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:15:18 by seongyle          #+#    #+#             */
/*   Updated: 2022/09/02 08:23:13 by seongyle         ###   ########seoul.kr  */
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
