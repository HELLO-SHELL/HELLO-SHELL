#include "../../include/minishell.h"
/*
1. 메시지를 전달하 듯한 변수명 사용해볼까?
2. 사용 함수 chdir, getcwd..?
3. 에러 처리?
*/
void  ft_cd(t_node *minishell)
{
    t_list *env_list;
    t_token *token_list;
    char *path;

    path = NULL;
    env_list = minishell->env_list;
    token_list = minishell->token_list->next;
    // go_to_home_directory
    if (token_list == NULL || token_list->value[0] == '~')
    {
        // path = ft_strdup(get_env_by_key(env_list, "HOME")->value);
        path = get_env_by_key(env_list, "HOME")->value;
    }

    if (chdir(path) != 0)
        print_error_message("fail CD _ 수정 필요");
    // free(path);
    // path = NULL;
    /*
    if (cd 뒤에 토큰 존재 여부)
        없으면 홈 디렉토리로 이동
    else if (토큰 있으면 에러 확인 isalpnum)
        있으면 에러 출력
    else if (~, / 있는지 확인)
        if (~있으면)
            홈 디렉토리
        else if (/있으면)
            루트 디렉토리
    else
        그 다음 문자열 확인
        if(현재 디렉토리에 있는 파일 이름이 있는지 확인)
            있으면 이동
        else
            없으면 에러 출력
    */
}