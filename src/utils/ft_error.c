/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:09:23 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 17:56:37 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	print_error_message(char *str)
{
	write(2, RED, ft_strlen(RED));
	ft_putendl_fd(str, STDERR_FILENO);
	write(2, COLOR_RESET, ft_strlen(COLOR_RESET));
}

void	error_exit(char *str)
{
	print_error_message(str);
	exit(EXIT_FAILURE);
}

void	error_two_exit(char *str1, char *str2)
{
	print_error_two_messages(str1, str2);
	exit(EXIT_FAILURE);
}

void	print_error_two_messages(char *str1, char *str2)
{
	write(2, RED, ft_strlen(RED));
	ft_putstr_fd("HELLO-SHELL: ", STDERR_FILENO);
	ft_putstr_fd(str1, STDERR_FILENO);
	ft_putendl_fd(str2, STDERR_FILENO);
	write(2, COLOR_RESET, ft_strlen(COLOR_RESET));
}

void	error_two_exit_status(int status, char *str1, char *str2)
{
	print_error_two_messages(str1, str2);
	exit(status);
}
