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
		idx++;
	}
}

static t_split	*init_split_list(char *str)
{
	t_split		*split;

	split = safe_malloc(sizeof(t_split));
	split->result = NULL;
	split->split_size = count_split_size(str);
	split->result = safe_malloc(sizeof(char *) * (split->split_size + 1));
	split->result[split->split_size] = NULL;
	return (split);
}

char	**command_split(char *str)
{
	t_split		*split;
	char		**result;
	int			i;

	if (!str)
		return (NULL);
	split = init_split_list(str);
	i = 0;
	make_result_from_line(split, str);
	result = safe_malloc(sizeof(char *) * (split->split_size + 1));
	result[split->split_size] = NULL;
	while (split->result[i] != NULL)
	{
		result[i] = ft_strdup(split->result[i]);
		free(split->result[i]);
		i++;
	}
	free(split->result);
	split->result = NULL;
	free(split);
	return (result);
}
