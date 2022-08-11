#include "../../include/minishell.h"

void	apply_redirection(char *filename, int mode)
{
	int	fd;
	if (mode == TK_RDINPUT)
	{
		fd = openfile(filename, READ);
		dup2(fd, STDIN_FILENO);
	}
	else if (mode == TK_RDOUTPUT)
	{
		fd = openfile(filename, WRITE);
		dup2(fd, STDOUT_FILENO);
	}
	else if (mode == TK_APPEND)
		fd = openfile(filename, APPEND);
}

void	apply_redirections(t_token *cmd_line)
{
	// 돌면서 redirect 를 찾습니다. < > >>
	// TK_RDINPUT TK_RDOUTPUT TK_APPEND
	
	// 다음 파일을 open(filename);
	// input 이면 dup2(파일, stdin_fileno) ...
	// 닫아줘야 할까요? close(filename)
}
