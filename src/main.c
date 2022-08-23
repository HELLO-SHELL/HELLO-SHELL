#include "../include/minishell.h"

t_minishell	g_minishell_info;

int main(int ac, char **av, char **env)
{
	// 전역으로 바꾸기
	// t_minishell	*minishell;

	// minishell = safe_malloc(sizeof(t_minishell));
	print_wallpaper();
	// minishell 구조체 초기화 
	// env_list
	env_linked_list(env);
	// init_minishell을 적절한 이름으로 변경 후
	// ps_list, pipes 초기화
	init_minishell();
	return (0);
}
