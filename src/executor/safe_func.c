/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:16:26 by jimin             #+#    #+#             */
/*   Updated: 2022/08/29 18:16:27 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	safe_dup2(int fd, int to_fd)
{
	if (fd >= 0 && to_fd >= 0 && dup2(fd, to_fd) == -1)
		error_exit("fail dup2()\n");
}

int	safe_openfile(char *filename, int mode)
{
	int	fd;

	fd = -1;
	if (mode == READ)
	{
		if (access(filename, F_OK))
		{
			print_error_two_messages(filename, ": No such file or directory");
			return (fd);
		}
		else
			fd = open(filename, O_RDONLY);
	}
	else if (mode == WRITE)
		fd = open(filename, O_TRUNC | O_CREAT | O_RDWR, 0644);
	else if (mode == APPEND)
		fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd < 0)
		print_error_two_messages(filename, ": Permission denied");
	return (fd);
}

void	safe_close_pipe(int *fd)
{
	if (*fd != -1)
	{
		if (close(*fd))
			print_error_message("fail close()\n");
		else
			*fd = -1;
	}
}

void	safe_close_pipes(t_pipes *p)
{
	safe_close_pipe(&p->prev_pipe[READ]);
	safe_close_pipe(&p->prev_pipe[WRITE]);
	safe_close_pipe(&p->next_pipe[READ]);
	safe_close_pipe(&p->next_pipe[WRITE]);
}
