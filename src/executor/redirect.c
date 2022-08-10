#include "../../include/minishell.h"

void	apply_redirection();

void	apply_redirections(t_token *cmd_line)
{
	// 돌면서 redirect 를 찾습니다. < > >>
	// TK_RDINPUT TK_RDOUTPUT TK_APPEND
	
	// 다음 파일을 open(filename);
	// input 이면 dup2(파일, stdin_fileno) ...
	// 닫아줘야 할까요? close(filename)
}
