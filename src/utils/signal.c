#include "../../include/minishell.h"

void get_new_prompt(int sig)
{
	(void)sig;
	// 제출할 때 주석 풀어주기
	// rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}