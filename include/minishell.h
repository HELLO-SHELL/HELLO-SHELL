#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "color.h"

enum e_token_type
{
	TK_EOF = 0,
	TK_PAREN_L = '(',
	TK_PAREN_R = ')',
	TK_RDINPUT = '<',
	TK_RDOUTPUT = '>',
	TK_HEREDOC = '<<',
	TK_APPEND = '>>',
	TK_PIPE = '|',
	TK_COMMAND,
	TK_WORD
};

typedef struct s_token
{
	int				type;
	char			*str;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

char	**command_split(char *str);
int		check_white_space(char c);
int		count_split_size(char *str);
int		check_size(char *line, char **str, int *i);
void	print_wallpaper(void);

#endif
