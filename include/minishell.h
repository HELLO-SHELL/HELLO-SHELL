/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:28:52 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:40:30 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <sys/stat.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <errno.h>
# include <sys/wait.h>
# include <string.h>
# include <fcntl.h>
# include "libft.h"
# include "constant.h"
# include "get_next_line.h"
# include "color.h"
# include "./minishell_struct.h"

# include "./minishell_src/minishell_built_in.h"
# include "./minishell_src/minishell_executor.h"
# include "./minishell_src/minishell_init.h"
# include "./minishell_src/minishell_parser.h"
# include "./minishell_src/minishell_utils.h"

extern t_minishell	g_minishell_info;

#endif
