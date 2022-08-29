/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constant.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seuol.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 18:30:51 by jaekim            #+#    #+#             */
/*   Updated: 2022/08/29 18:30:52 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANT_H
# define CONSTANT_H

enum e_token_type
{
	TK_EOF,
	TK_RDINPUT,
	TK_RDOUTPUT,
	TK_APPEND,
	TK_PIPE,
	TK_COMMAND,
	TK_FILE,
	TK_HEREDOC,
	TK_DELIM,
	TK_WORD
};

enum e_file_permission_type
{
	READ,
	WRITE,
	APPEND,
	EXECUTE
};

enum e_file_type
{
	DIRECTORY,
	COMMON_FILE,
	NOTFOUND
};

enum e_boolean {
	FAILURE = 0,
	SUCCESS = 1,
};

enum e_env_key_result {
	ENV_KEY_OTHERS = 1,
	ENV_KEY_QUESTION = 2,
};

# define CD "cd"
# define ENV "env"
# define PWD "pwd"
# define EXIT "exit"
# define ECHO "echo"
# define UNSET "unset"
# define EXPORT "export"

# define TRUE 1
# define FALSE 0

# define EXIT_255 255

#endif
