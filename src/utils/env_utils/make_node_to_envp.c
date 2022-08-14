#include "../../../include/minishell.h"

static void count_envp_size(t_list *env_list)
{
	int		count;
	t_list	*curr;

	count = 0;
	curr = env_list;
	while (curr)
	{
		count += ft_strlen(((t_env *)(curr->content))->key) + 1;
		count += ft_strlen(((t_env *)(curr->content))->value) + 1;
		curr = curr->next;
	}
	return (count);
}

void make_node_to_envp(t_list *env_list)
{
	// key와 value의 크기를 모두 더해주고, 할당해주는 함수 필요
	// key와 value size 에 맞춰서 envp 에 욱여넣음

}