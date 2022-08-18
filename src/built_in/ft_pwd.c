#include "../../include/minishell.h"

int ft_pwd(void)
{
	char	*buf;

	// 환경변수에서 pwd를 가져와서 출력하는게 과제 의도에는 맞을듯 싶다.
	// 벗, 이게 훨씬 편하긴함... 벗, 경로가 안바뀜 -> 이건 cd에서 해야됨.
	buf = getcwd(NULL, 0);
	if (!buf)
	{
		free(buf);
		return (0);
	}
	printf("%s\n", buf);
	free(buf);
	return (1);
}
