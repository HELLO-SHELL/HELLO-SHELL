#include "../../include/minishell.h"

// argc 1개 일 때 -> exit -> exit 출력하면서 종료
	// argc 2개 일 때 
	// 문자, 문자+숫자(특수문자..?) helloshell: exit: 문자열: numeric argument required 출력 하고 종료
	// 문자, 문자+숫자일때 argc 3개 이상이면 helloshell: exit: 문자열(첫번째 인자): numeric argument required 출력 하고 종료
	
	// 숫자이면, exit 출력하면서 종료 echo $? 하면 종료 상태값 저장
	// argc 3개 이상
	// 첫번째 인자가 숫자이면, helloshell: exit: too many argumnents 출력하고 종료x 

void	ft_exit(void)
{
	char	**argv;
	int		ac;
	int		i;
	int		j;

	argv = g_minishell.ps_list->argv;
	ac = 0;
	i = 0;
	j = 0;
	while (argv[ac] != NULL)
		ac++;
	if (ac == 1)
	{
		ft_putendl_fd(EXIT, STDOUT_FILENO);
		exit(EXIT_SUCCESS);
	}
	i++;
	if (ac >= 2)
	{
		while (argv[i][j] != '\0') // while (1)
		{
			if (!ft_strchr("0123456789", argv[i][j]))
				break ;
			j++;
			if (argv[i][j] == '\0')
			{
				if (ac == 2)
				{
					g_minishell.last_status = ft_atoi(argv[1]);
					if (argv[1][0] == '0')
						ft_putendl_fd(EXIT, STDOUT_FILENO);
					else
						print_error_message(EXIT);
					exit(ft_atoi(argv[1]));
				}
				else
					print_error_message("helloshell: exit: too many arguments");
				return ;
			}
		}
		i++;
		g_minishell.last_status = EXIT_255;
		ft_putstr_fd("helloshell: exit: ", STDERR_FILENO);
		ft_putstr_fd(argv[1], STDERR_FILENO);
		ft_putendl_fd(": numeric argument required", STDERR_FILENO);
		exit(EXIT_255);		
	}	
}
