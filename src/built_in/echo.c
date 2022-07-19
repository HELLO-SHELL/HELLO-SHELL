#include "../../include/minishell.h"

void	clear_double_pointer(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		argv[i] = NULL;
		i++;
	}
	free(argv);
	argv = NULL;
}

void	print_arg_with_idx(char **argv, int idx, int is_flag)
{
	while (argv[idx])
	{
		printf("%s", argv[idx]);
		if (argv[idx + 1] != NULL)
			printf(" ");
		idx++;
	}
	if (!is_flag)
		printf("\n");
	clear_double_pointer(argv);
}

int	check_flag(char **argv, int *idx, int *is_flag)
{
	int j;

	j = 0;
	while (argv[*idx])
	{
		if (argv[*idx][j] == '-' && argv[*idx][j + 1] == 'n')
		{
			j++;
			while (argv[*idx][j] == 'n')
				j++;
			if (check_white_space(argv[*idx][j]) || argv[*idx][j] == '\0')
			{
				(*idx)++;
				*is_flag = TRUE;
				j = 0;
				continue;
			}
		}
		return (*idx);
	}
	return (*idx);
}

int	echo(char *str)
{
	char	**argv;
	int		idx;
	int		is_flag;

	argv = command_split(str);
	idx = 0;
	is_flag = FALSE;
	check_flag(argv, &idx, &is_flag);
	print_arg_with_idx(argv, idx, is_flag);
	return (1);
}

int main()
{
	// char *str = "aa bb c ";
	// echo(str);
	// printf("+++++++++++++++++");

	// char *str1 = "-n aa bb c ";
	// echo(str1);
	// printf("+++++++++++++++++");

	// char *str2 = "----n aa bb c ";
	// echo(str2);
	// printf("+++++++++++++++++");

	// char *str3 = "-nnnnnn aa bb c ";
	// echo(str3);
	// printf("+++++++++++++++++");

	// char *str4 = "------n -nnn -n aa bb cc";
	// echo(str4);
	// printf("+++++++++++++++++");

	// char *str5 = "-n -n -n -n ---n aa bb c ";
	// echo(str5);
	// printf("+++++++++++++++++");

	// char *str6 = "-nnn -nnn aa bb c ";
	// echo(str6);
	// printf("+++++++++++++++++");
}