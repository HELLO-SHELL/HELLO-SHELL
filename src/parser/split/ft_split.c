#include "../../../include/minishell.h"

static void	make_result_from_line(t_split *split, char *line)
{
	int		idx;

	split->i = 0;
	split->j = 0;
	idx = 0;
	split->str = NULL;
	while (line[split->i] != '\0' && idx < split->split_size)
	{
		split_line(split, line);
		split->result[idx] = split->str;
		split->str = NULL;
		if (is_same_string(split->result[idx], "|") || line[split->i] != '|')
			split->i++;
		idx++;
	}
}

char	**command_split(char *str)
{
	t_split		*split;
	char		**result;
	int			i;

	if (!str)
		return (NULL);
	split = safe_malloc(sizeof(t_split));
	split->result = NULL;
	// 파이프 및 리다이렉트(|,<,>,<<,>>, ', ") 단위를 추가해야하기 때문에 추가
	split->split_size = count_split_size(str);
	split->result = safe_malloc(sizeof(char *) * (split->split_size + 1));
	split->result[split->split_size] = NULL;
	make_result_from_line(split, str);
	i = 0;
	result = safe_malloc(sizeof(char *) * (split->split_size + 1));
	result[split->split_size] = NULL;
	while (i < split->split_size)
	{
		result[i] = ft_strdup(split->result[i]);
		// 아래 나중에 삭제
		ft_putstr_fd("splitted str ",1);
		ft_putstr_fd(split->result[i],1);
		ft_putstr_fd("\n",1);
		free(split->result[i]);
		i++;
	}
	free(split->result);
	split->result = NULL;
	free(split);
	return (result);
}
