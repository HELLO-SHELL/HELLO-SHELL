#include "../../include/minishell.h"

void	safe_free(void **p)
{
	if (*p)
	{
		free(*p);
		*p = NULL;
	}
	return ;
}

void    *del(t_list **env_lsit, char *key)
{
    safe_free((t_list *)(*env_list->conten)->key));
    safe_free((t_list *)(*env_list->conten)->value));
}

void    ft_unset(t_node *minishell)
{
    // env_list를 들고 다닐 커서 지정
    t_list *curr;
    t_token *커서지정;

    curr = minishell->env_list;
    // 첫 번째 토큰은 unset
    if (두 번째 토큰이 없는 경우)
        새로운 프롬프트 출력;
    while (2 ~ n 번째 토큰 순회)
    {
        // 두 번째 토큰 확인
        if (토큰이 있을 경우)
            ft_lstdelone(토큰, del함수(&env_list));
        커서지정 = 커서지정->next;
    }
}
