#include "../include/minishell.h"

static t_env	*ft_env_lstlast(t_env *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

static void	ft_env_lstadd_back(t_env **lst, t_env *new)
{
	t_env	*result;

	result = ft_env_lstlast(*lst);
	if (!result)
		*lst = new;
	else
		result->next = new;
}

static t_env	*ft_env_new(void *value)
{
	t_env	*result;

	result = (t_env *)malloc(sizeof(t_env));
	if (!result)
		return (NULL);
	result->value = value;
	result->next = NULL;
	return (result);
}

int main(int ac, char **av, char **env)
{
    // char    *input;
    t_env   *env_list;
    t_env   *curr;
    int i = 0;

    // printf("%s\n", env[0]);
    while (env[i])
    {
        printf("Before List : %s", env[i]);
        i++;
    }
    printf("---------------------------------");
    // 여기부터 다시 진행해야함.
    // env 구조체의 char *value 도 malloc을 해야함.
    // malloc을 하려면, strlen로 각 문자열의 길이를 구해야 함.
    /*----------------------------------------------*/
    
    // while(1)
    // {
    //     input = readline("HELLO-SHELL-0.0$ ");
    //     if (input)
    //         printf("%s\n", input);
    //     else
    //         break ;
    //     add_history(input);
    //     free(input);
    // }
    system("leaks minishell");
    return(0);
}