#include "../../include/minishell.h"
void	get_new_prompt(int sig)
{
	(void)sig;
	
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}

void	heredoc_new_prompt(int sig)
{
	(void)sig;
	rl_replace_line("", 0);
	write(1, "\n", 1);
	rl_on_new_line();
	exit(EXIT_FAILURE);
}
